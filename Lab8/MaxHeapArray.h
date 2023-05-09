/** @file main.cpp * /
* @author Valerie Williams
* @date 4/23/2023
* @version 1
* Allows a user to create priority queue that has max heap implementation.
*/

#ifndef MAXHEAPARRAY_H
#define MAXHEAPARRAY_H

#include <string>
#include <iostream>

using namespace std;

template <typename T>
class MaxHeapArray{
public:
    MaxHeapArray();
    MaxHeapArray(const MaxHeapArray& orig);
    virtual ~MaxHeapArray();
    
    void maxHeapify(int i);
    T dequeue();
    void printHeap();
    
    //interface methods
    bool isEmpty() const;
    int getItemCount() const;
    T peek() const;
    bool add(const T& newItem);
    bool remove();
    void clear();
    
private:
    static const int ROOT_INDEX = 0;
    static const int CAPACITY = 5000;
    int itemCount;
    T* items;  //this is the array of items in the heap --- once instantiated you can treat it the same as any array
    
    int getLeftChild(int currNode) const;
    int getRightChild(int currNode) const;
    int getParent(int currNode) const;
    
    bool isLeaf(int currNode) const;
    
    void percolateDown(int subTree);
};

#endif /* ARRAYMAXHEAP_H */


/**
 * Constructs a priority queue (with max heap implementation) with no parameters
*/
template <class T>
MaxHeapArray<T>::MaxHeapArray()
{
    itemCount = 0;
    items = new T[CAPACITY];
}

/**
 * Constructs a priority queue (with max heap implementation) from another
 * priority queue.
 * @param orig the priority queue to copy
*/
template <class T>
MaxHeapArray<T>::MaxHeapArray(const MaxHeapArray& orig)
{

    for (int i = 0; i < orig.getItemCount(); i++)
    {

        this->add(orig.dequeue());

    }

}

/**
 * Destroys a priority queue (with max heap implementation) 
*/
template <class T>
MaxHeapArray<T>::~MaxHeapArray()
{

}

//interface methods

/**
 * Adds a new node to the priority queue (with max heap implementation).
 * @param newItem the new node to add
*/
template <class T>
bool MaxHeapArray<T>::add(const T& newItem)
{

    if (itemCount >= CAPACITY){
        cout << "heap full" << endl;
        return false;
    }//end if

    items[itemCount] = newItem;

    int currentPosition = itemCount;

    bool inPlace = false;

    //percolate up
    while (currentPosition > 0 && !inPlace){
        int parent = getParent(currentPosition);
        if (items[currentPosition] < items[parent])
            inPlace = true;
        else {
            swap(items[currentPosition], items[parent]);
            // cout << "swapping " << items[currentPosition] << " and " << items[parent] << endl;
            currentPosition = parent;
        }//end else


    }

    itemCount++;
    return true;

}

/**
 * Clears all the data from the priority queue (with max heap implementation).
*/
template <class T>
void MaxHeapArray<T>::clear()
{
    itemCount = 0;
}

/**
 * Returns the number of items in the priority queue (with max heap implementation)
*/
template <class T>
int MaxHeapArray<T>::getItemCount() const
{
    return itemCount;
}

/**
 * Returns the front of the priority queue (with max heap implementation)
 * @return the object at the front (also the maximum object in the priority queue)
*/
template <class T>
T MaxHeapArray<T>::peek() const
{

    if (isEmpty())
    {
    cout << "empty heap - returning -999" << endl;
    }
    return items[0];

}

/**
 * Removes the front object from the priority queue (with max heap implementation)
 * @return true if the front object has been removed, false if was not
*/
template <class T>
bool MaxHeapArray<T>::remove()
{
    
    if (isEmpty()){
        cout << "empty heap..." << endl;
        return false;
    }

    else{
        itemCount--;
        items[0] = items[itemCount];
        percolateDown(0);

    }

    return true;

}

/**
 * Checks if the priority queue (with max heap implementation) is empty
 * @return true if empty, false if not
*/
template <class T>
bool MaxHeapArray<T>::isEmpty() const
{
    return (itemCount == 0);
}

//private methods
/**
 * Returns the index of the left child of a node in the
 * priority queue (with max heap implementation)
 * @param currNode the index of the current node
 * @return the index of the current node's left child
*/
template <class T>
int MaxHeapArray<T>::getLeftChild(int currNode) const
{
    return (currNode * 2 + 1);   
}

/**
 * Returns the index of the right child of a node in the
 * priority queue (with max heap implementation)
 * @param currNode the index of the current node
 * @return the index of the current node's right child
*/
template <class T>
int MaxHeapArray<T>::getRightChild(int currNode) const
{
    return (currNode * 2 + 2);
}

/**
 * Returns the index of a node's parent in the
 * priority queue (with max heap implementation)
 * @param currNode the index of the current node
 * @return the index of the current node's parent
*/
template <class T>
int MaxHeapArray<T>::getParent(int currNode) const
{
    return ((currNode - 1) / 2);
}

/**
 * Checks if a node is a leaf
 * @param currNode the index of the current node
 * @return true if the current node is a leaf, false if not
*/
template <class T>
bool MaxHeapArray<T>::isLeaf(int currNode) const
{
    return (getLeftChild(currNode) >= itemCount); 
}

//reheapify
template <class T>
void MaxHeapArray<T>::percolateDown(int currentNode)
{
    
    if (!isLeaf(currentNode)){
        int leftChild = getLeftChild(currentNode);
        int maxChild = leftChild;
        int rightChild = getRightChild(currentNode);

        if (rightChild < itemCount) { //there is actually a right child
            if (items[rightChild] > items[leftChild])
                maxChild = rightChild;
        }//maxChild has the index of the greater child

        if (items[currentNode] < items[maxChild]){
            swap(items[currentNode], items[maxChild]);
            percolateDown(maxChild);
        }//end if
    }//end if

}

/**
 * Puts the priority queue (with max heap implementation) back in
 * max-heap order.
 * @param i the current index
*/
template <class T>
void MaxHeapArray<T>::maxHeapify(int i)
{

    int largest;

    int leftIndex = 2*i;
    int rightIndex = (2*i) + 1;

    if (leftIndex <= this->getItemCount() && items[leftIndex] > items[i])
    {
        largest = leftIndex;
    }
    else
    {
        largest = i;
    }

    if (rightIndex <= this->getItemCount() && items[rightIndex] > items[largest])
    {
        largest = rightIndex;
    }
    
    if (largest != i)
    {
        swap(items[i], items[largest]);
        maxHeapify(largest);
    }

}

/**
 * Removes and returns the item at the front of the priority queue.
 * @return the maximum item of the priority queue.
*/
template <class T>
T MaxHeapArray<T>::dequeue()
{

   T max = items[0];
   items[0] = items[itemCount - 1];
   itemCount--;
   
   maxHeapify(0);
   return max;

}

template <class T>
void MaxHeapArray<T>::printHeap(){

   for (int i = 0; i < itemCount; i++)
      cout << items[i] << endl;
      

}//end printHeap()
