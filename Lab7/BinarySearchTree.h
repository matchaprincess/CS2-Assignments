/** @file BinarySearchTree.h * /
* @author Valerie Williams
* @date 4/4/2023
* @version 1
* A class to allow users to create binary search trees.
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"
#include "BSTInterface.h"
#include <iostream>
#include <iomanip>
#include "Airport.h"

using namespace std;

/**
 * The purpose of this class is to allow a user to create and do operations on a Binary Search Tree.
*/
template<typename T>
class BinarySearchTree
{
    public:
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& orig);
        virtual ~BinarySearchTree();


        //interface methods
        void loadTreeData(const T data[], const int count);
        bool isEmpty() const;
        bool add(const T& newItem);
        void removeItem(const T& deleteItem);
        void clearTree();
        bool contains(const T& findItem) const;
        Node<T>* getRoot() const;

        void inorderTraverse() const;
        void preorderTraverse() const;
        void postorderTraverse() const;

        void print2D();

        // non-interface methods for airport specific trees

        // search methods
        void searchByCode(Node<T>* treeRoot, const string& targetCode);
        void searchByState(Node<T>* treeRoot, string targetCode);
        void searchByMinPassenger(Node<T>* treeRoot, int targetPassengers);

        // report methods
        void averageDailyPassengers(Node<T>* treeRoot);
        void averageDailyFlights(Node<T>* treeRoot);
        void displayAllAirports(Node<T>* treeRoot);

        // max/min methods (for use w any numeric data member)
        T maxObjByDataMember(Node<T>* currRoot, string dataMember);
        T minObjByDataMember(Node<T>* currRoot, string dataMember);

        // edit methods
        bool editFlight(Node<T>* currRoot, string targetCode, int newFlights);
        bool editFreight(Node<T>* currRoot, string targetCode, int newFreight);
        bool editPassengers(Node<T>* currRoot, string targetCode, int newPassengers);

        // etc helper methods
        void inorder_maxObj_helper(Node<T>* currRoot, T& currentMaximum, int& maxValue, string dataMember);
        void inorder_minObj_helper(Node<T>* currRoot, T& currentMinimum, int& minValue, string dataMember);

    private:

        Node<T>* root;

        //recursive methods
        void destroyTree(Node<T>* currRoot);

        Node<T>* deleteNode(Node<T>* currRoot, const T& deleteItem);

        Node<T>* minValueNode(Node<T>* node);
        Node<T>* maxValueNode(Node<T>* node);
        Node<T>* copyTree(const Node<T>* currRoot) const;
        Node<T>* placeNode(Node<T>* currRoot, Node<T>* newNode);
        bool findNode(Node<T>* currRoot, const T& item) const;
        void inorder(Node<T>* currRoot) const;
        void preorder(Node<T>* currRoot) const;
        void postorder(Node<T>* currRoot) const;

        void print2DUtil(Node<T>* root, int space);

};


/**
 * Creates a binary search tree with no parameters.
*/
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}


/**
 * Creates a copy of another binary search tree.
 * @param orig The binary search tree to copy.  
*/
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& orig) {

    root = this->copyTree(orig.root);
}



/**
 * Deletes a binary search tree object.
*/
template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    clearTree();
}

/**
 * Returns the root of a binary search tree object.
 * @return The root of a binary search tree, 
*/
template<typename T>
Node<T>* BinarySearchTree<T>::getRoot() const
{
    return root;
}

/**
 * Creates a binary search tree from an array.
 * @param data the array of data to be put in the binary search tree
 * @param count the number of items in the array
*/
template <class T>
void BinarySearchTree<T>::loadTreeData(const T data[], const int count)
{
    for (int i = 0; i < count; i++) {
            add(data[i]);
    }
}



//interface methods

/**
 * Checks whether a binary search tree is empty or not.
 * @return true if the BST is empty, false if not.
*/
template <class T>
bool BinarySearchTree<T>::isEmpty() const {
    return root = nullptr;
}



/**
 * Adds a new item to the binary tree.
 * @param newItem the new item to add
*/
template <class T>
bool BinarySearchTree<T>::add(const T& newItem) {
    Node<T>* newNode = new Node<T>(newItem);
    root = placeNode(root, newNode);
    return true;
}


/**
 * Places a node in the correct order in the binary search tree.
 * @param currRoot the current node of the binary search tree
 * @param newNode the new node to place in the binary search tree
 * @return the node that has been added to the binary search tree
*/
template <class T>
Node<T>* BinarySearchTree<T>::placeNode(Node<T>* currRoot, Node<T>* newNode) {
    if (currRoot == nullptr){
        //cout << "added " << newNode->getItem() << endl;
        return newNode;
    }//end if
    else {
        if (newNode->getItem() < currRoot->getItem()) {
            //cout << "Going left" << endl;
            Node<T>* tempPtr = placeNode(currRoot->left, newNode);
            currRoot->left = tempPtr;
        } else {
            //cout << "Going right" << endl;
            currRoot->right = placeNode(currRoot->right, newNode);
        }
        return currRoot;
    }
}


/**
 * Checks if an item exists in the binary search tree.
 * @param findItem the item to find
 * @return true if the item exists in the BST, false if not
*/
template <class T>
bool BinarySearchTree<T>::contains(const T& findItem) const {
    
    if (findNode(root, findItem) == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}


/**
 * Removes an item from the binary search tree.
 * @param delItem the item to remove
*/
template <class T>
void  BinarySearchTree<T>::removeItem(const T& delItem) {

    root = deleteNode(root, delItem);

}


/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
template <class T>
Node<T>* BinarySearchTree<T>::minValueNode(Node<T>* node)
{
    //cout << "minValueNode(" << node->getItem() << "): Begin..." << endl;
    Node<T>* current = node;

    /* loop to find the leftmost leaf */
    while (current && current->left != nullptr) {
        current = current->left;
    }

    //cout << "minValueNode(" << node->getItem() << "): End: current = " << current << endl;
    return current;
}


/* Given a non-empty binary search tree, return the node
with maximum key value found in that tree. Note that the
entire tree does not need to be searched. */
template <class T>
Node<T>* BinarySearchTree<T>::maxValueNode(Node<T>* node)
{
    //cout << "minValueNode(" << node->getItem() << "): Begin..." << endl;
    Node<T>* current = node;

    /* loop to find the leftmost leaf */
    while (current && current->right != nullptr) {
        current = current->right;
    }

    //cout << "minValueNode(" << node->getItem() << "): End: current = " << current << endl;
    return current;
}



/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
template <class T>
Node<T>* BinarySearchTree<T>::deleteNode(Node<T>* currRoot, const T& deleteItem)
{

    // base case
    if (currRoot == nullptr) {

        return nullptr;
    }

    // If the item to be deleted is < than the root's item then look in the left subtree

    if (deleteItem < currRoot->getItem()) {

        currRoot->left = deleteNode(currRoot->left, deleteItem);
    }

    // If the item to be deleted is > than the root's item then look in right subtree
    else if (deleteItem > currRoot->getItem()) {

        currRoot->right = deleteNode(currRoot->right, deleteItem);
    }

    else {
        // The deleteItem is same as root's item.
        // Deleting the root node.
        if (currRoot->left == nullptr && currRoot->right == nullptr) {
            return nullptr;
        }

        // node with only one child or no child
        else if (currRoot->left == nullptr) {

            Node<T>* temp = currRoot->right;
            delete(currRoot);

            return temp;
        }
        else if (currRoot->right == nullptr) {

            Node<T>* temp = currRoot->left;
            delete(currRoot);

            return temp;
        }

        // node with two children: Get the largest in the left subtree (or smallest in the right subtree)
        Node<T>* temp = maxValueNode(currRoot->left);   //could also use Node<T>* temp = minValueNode(currRoot->right);
        //Node<T>* temp = minValueNode(currRoot->right) ;

        // Copy the inorder successor's content to this node
        currRoot->setItem(temp->getItem());

        currRoot->left = deleteNode(currRoot->left, temp->getItem());
        //currRoot->right = deleteNode(currRoo->right, temp-gettItem());
    }


    return currRoot;
}








/**
 * Removes all data from the binary search tree
*/
template <class T>
void BinarySearchTree<T>::clearTree() {
    //call destroyTree with root
    destroyTree(root);
    root = nullptr;

}




//recursive methods

/**
 * Copies the contents of one tree to a new tree.
 * @param currRoot the current root/node
*/
template <class T>
Node<T>* BinarySearchTree<T>::copyTree(const Node<T>* currRoot) const {
    //preorder traversal
    Node<T>* newTree = nullptr;
    if (currRoot != nullptr) {
        newTree = new Node<T>(currRoot->getItem(), nullptr, nullptr);
        newTree->left = copyTree(currRoot->left);
        newTree->right =copyTree(currRoot->right);
    }
    return newTree;
}


/**
 * Checks if a node exists in a binary search tree.
 * @param currRoot the current root/node of a tree
 * @param item the item to search for
*/
template <class T>
bool BinarySearchTree<T>::findNode(Node<T>* currRoot, const T& item) const {

/* if (base case)
 *  return some value
 * else
 *  recursive call with root of new subtree
 */

    if (currRoot == nullptr)
    {
        return false; 
    }

    if (currRoot->getItem() == item)
    {
        cout << currRoot->getItem() << endl;
        return true;
    }
    else 
    {
        if (item > currRoot->getItem())
        {
            findNode(currRoot->right, item);
        }

        if (item < currRoot->getItem())
        {
            findNode(currRoot->left, item);
        }
    }


 return false;
}


/**
 * Destroys a binary search tree.
 * @param currRoot the current root/node of the tree
*/
template <typename T>
void BinarySearchTree<T>::destroyTree(Node<T>* currRoot) {
    //post order traversal
    if(currRoot != nullptr){

        destroyTree(currRoot->left);
        destroyTree(currRoot->right);
        delete currRoot;
        currRoot = nullptr;
    }//end if
}


//traversal

/**
 * Traverses the binary search tree in order.
*/
template <typename T>
void BinarySearchTree<T>::inorderTraverse() const { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    inorder(root);//, visit);
}




/**
 * Helper method for traversing the BST in order.
*/
template <typename T>
void BinarySearchTree<T>::inorder(Node<T>* currRoot) const {//, void visit(T& item)) const {
    
    if(currRoot != nullptr){
        inorder(currRoot->left);             //, visit);

        T item = currRoot->getItem();
        cout << item << endl;
        //visit()
        inorder(currRoot->right);             //, visit);
    }

}


//traversal

/**
 * Pre-orderly traverses a BST. (root, left, right)
*/
template <typename T>
void BinarySearchTree<T>::preorderTraverse() const { //void visit(T& item)) const {

    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return;
    }
    preorder(root);//, visit);
}


template <typename T>
void BinarySearchTree<T>::preorder(Node<T>* currRoot) const {//, void visit(T& item)) const {
    if(currRoot != nullptr){

        //visit()
        T item = currRoot->getItem();
        cout << item << "  ";

        preorder(currRoot->left);             //, visit);

        preorder(currRoot->right);             //, visit);
    }

}//end preorder


/**
 * Post-orderly traverses a BST. (left, right, root)
*/
template <typename T>
void BinarySearchTree<T>::postorder(Node<T>* currRoot) const
{

    if (currRoot != nullptr)
    {

        // go left
        postorder(currRoot->left);

        // go right
        postorder(currRoot->right);

        // visit
        T item = currRoot->getItem();
        cout << item << endl;

    }

}

template <typename T>
void BinarySearchTree<T>::postorderTraverse() const
{

    if (root == nullptr)
    {

        cout << "The tree is empty." << endl;
        return;
        
    }

    postorder(root);//, visit);

}















const int COUNT = 10;

// Function to print binary tree in 2D
// It does reverse inorder traversal
//
//  From:  https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
template <typename T>
void BinarySearchTree<T>::print2DUtil(Node<T>* currRoot, int space)
{
    // Base case
    if (currRoot == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(currRoot->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << currRoot->getItem() << endl;

    // Process left child
    print2DUtil(currRoot->left, space);
}











// Wrapper over print2DUtil()
//  From:  https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
template <typename T>
void BinarySearchTree<T>::print2D()
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

// non-interface methods

// search methods

/**
 * Searches the binary search tree for an object with a specific IATA code
 * and displays its information.
 * @param treeRoot a root of the BST
 * @param targetCode the iata code of the item to search for
*/
template <typename T>
void BinarySearchTree<T>::searchByCode(Node<T>* treeRoot, const string& targetCode)
{

    if(treeRoot != nullptr){

        searchByCode(treeRoot->left, targetCode);             //, visit);

        T tempAirport = treeRoot->getItem();
        if (tempAirport.getIata() == targetCode)
        {
            cout << tempAirport << endl;

        }
       
        //visit()
        searchByCode(treeRoot->right, targetCode);             //, visit);
    }

    

}

/**
 * Searches the binary search tree for an object with a specific state
 * and displays its information.
 * @param treeRoot a root of the BST
 * @param targetState the state of the item to search for
*/
template <typename T>
void BinarySearchTree<T>::searchByState(Node<T>* treeRoot, string targetState)
{

     if(treeRoot != nullptr){

        searchByState(treeRoot->left, targetState);             //, visit);

        T tempAirport = treeRoot->getItem();
        if (tempAirport.getState() == targetState)
        {
            cout << "Airport Name: " << tempAirport.getName() << endl;
            cout << "City: " << tempAirport.getCity() << endl;
            cout << "Code: " << tempAirport.getIata() << endl;

        }
       
        //visit()
        searchByState(treeRoot->right, targetState);             //, visit);
    }   

}

/**
 * Searches the binary search tree for an object with a specific number of
 * minimum passengers and displays its information.
 * @param treeRoot a root of the BST
 * @param targetPassengers the minimum number of passengers to look for
*/
template <typename T>
void BinarySearchTree<T>::searchByMinPassenger(Node<T>* treeRoot, int targetPassengers)
{
        
    if(treeRoot != nullptr){

        searchByMinPassenger(treeRoot->left, targetPassengers);             //, visit);

        T tempAirport = treeRoot->getItem();
        if (tempAirport.getNumPassengers() >= targetPassengers)
        {
            cout << tempAirport << endl;

        }
       
        //visit()
        searchByMinPassenger(treeRoot->right, targetPassengers);             //, visit);
    }

}

// report methods

/**
 * Displays all airports in the binary search tree in a neat table.
 * @param treeRoot the root of a BST
*/
template <typename T>
void BinarySearchTree<T>::displayAllAirports(Node<T>* treeRoot)
{
        
    if(treeRoot != nullptr){
        displayAllAirports(treeRoot->left);             //, visit);

        T item = treeRoot->getItem();
        

            cout << setfill(' ');
            cout << setw(60) << item.getName() << setw(15) << item.getState() << setw(25) << item.getCity() <<  setw(10) << item.getIata();
            cout << setw(15) << item.getNumPassengers() << setw(20) << item.getNumFlights() << setw(20) << item.getFreight() << endl;

        //visit()
        displayAllAirports(treeRoot->right);             //, visit);
    }

}

/**
 * Displays all airports in the binary search tree and their average daily passengers
 * in a table format.
 * @param treeRoot the root of a BST
*/
template <typename T>
void BinarySearchTree<T>::averageDailyPassengers(Node<T>* treeRoot)
{

    if(treeRoot != nullptr){

        averageDailyPassengers(treeRoot->left);             //, visit);

        // name city state code
        T tempAirport = treeRoot->getItem();
        int average = tempAirport.getNumPassengers() / 365;
        cout << setw(75) << tempAirport.getName() << setw(30) << tempAirport.getCity() <<
            setw(20) << tempAirport.getState() << setw(20) << tempAirport.getIata() <<
            setw(20) << average << endl;

        //visit()
        averageDailyPassengers(treeRoot->right);             //, visit);
    }

}

/**
 * Displays all airports in the binary search tree and their average daily flights
 * in a table format.
 * @param treeRoot the root of a BST
*/
template <typename T>
void BinarySearchTree<T>::averageDailyFlights(Node<T>* treeRoot)
{

    if(treeRoot != nullptr){

        averageDailyFlights(treeRoot->left);             //, visit);

        // name city state code
        T tempAirport = treeRoot->getItem();
        int average = tempAirport.getNumFlights() / 365;
        cout << setw(75) << tempAirport.getName() << setw(30) << tempAirport.getCity() <<
            setw(20) << tempAirport.getState() << setw(20) << tempAirport.getIata() <<
            setw(20) << average << endl;

        //visit()
        averageDailyFlights(treeRoot->right);             //, visit);
    }

}

/**
 * Displays the maximum object given a data member to compare to.
 * @param currRoot the root of a BST
 * @param currentMaximum the current maximum object 
 * @param maxValue the current maximum value
 * @param dataMember the data member used to make comparisons
*/
template <typename T>
void BinarySearchTree<T>::inorder_maxObj_helper(Node<T>* currRoot, T& currentMaximum, int& maxValue, string dataMember)
{

    if (currRoot)
    {
        // move left
        inorder_maxObj_helper(currRoot->left, currentMaximum, maxValue, dataMember);

        // compare values based on data member
        if (dataMember == "numPassengers")
        {

            int currDataValue = currRoot->getItem().getNumPassengers();
            if (currDataValue > maxValue)
            {

                currentMaximum = currRoot->getItem();
                maxValue = currDataValue;

            }
        
        }

        else if (dataMember == "numFlights")
        {

            int currDataValue = currRoot->getItem().getNumFlights();
            if (currDataValue > maxValue)
            {

                currentMaximum = currRoot->getItem();
                maxValue = currDataValue;

            }

        }

        else if (dataMember == "freightInTons")
        {

            int currDataValue = currRoot->getItem().getFreight();
            if (currDataValue > maxValue)
            {

                currentMaximum = currRoot->getItem();
                maxValue = currDataValue;

            }

        }

        else 
        {
            cout << "Invalid data member for comparison."; // this should theoretically never occur
        }

        // move right
        inorder_maxObj_helper(currRoot->right, currentMaximum, maxValue, dataMember);
    }

}

/**
 * Displays the maximum object given a data member to compare to.
 * @param currRoot the root of a BST
 * @param currentMinimum the current minimum object 
 * @param minValue the current minimu value
 * @param dataMember the data member used to make comparisons
*/
template <typename T>
void BinarySearchTree<T>::inorder_minObj_helper(Node<T>* currRoot, T& currentMinimum, int& minValue, string dataMember)
{

    if (currRoot)
    {
        // move left
        inorder_minObj_helper(currRoot->left, currentMinimum, minValue, dataMember);

        // compare values based on data member
        if (dataMember == "numPassengers")
        {

            int currDataValue = currRoot->getItem().getNumPassengers();
            if (currDataValue < minValue)
            {

                currentMinimum = currRoot->getItem();
                minValue = currDataValue;

            }
        
        }

        else if (dataMember == "numFlights")
        {

            int currDataValue = currRoot->getItem().getNumFlights();
            if (currDataValue < minValue)
            {

                currentMinimum = currRoot->getItem();
                minValue = currDataValue;

            }

        }

        else if (dataMember == "freightInTons")
        {

            int currDataValue = currRoot->getItem().getFreight();
            if (currDataValue < minValue)
            {

                currentMinimum = currRoot->getItem();
                minValue = currDataValue;

            }

        }

        else 
        {
            cout << "Invalid data member for comparison."; // this should theoretically never occur
        }

        // move right
        inorder_minObj_helper(currRoot->right, currentMinimum, minValue, dataMember);

    }

}


template <typename T>
T BinarySearchTree<T>::maxObjByDataMember(Node<T>* currRoot, string dataMember)
{

    // declare necessary variables
    int maxValue = 0;
    T currentMaximum;

    // in order traversal helper method (compares data mmebers)
    inorder_maxObj_helper(currRoot, currentMaximum, maxValue, dataMember);

    return currentMaximum;

}

template <typename T>
T BinarySearchTree<T>::minObjByDataMember(Node<T>* currRoot, string dataMember)
{

    // declare necessary variables
    int minValue = 0;
    T currentMinimum;

    // in order traversal helper method (compares data mmebers)
    inorder_minObj_helper(currRoot, currentMinimum, minValue, dataMember);
    
    // return the max object
    return currentMinimum;

}


// edit methods
/**
 * Edits an airport's number of flights in the BST.
 * @param currRoot the root of a BST
 * @param targetCode the IATA code of the airport to edit
 * @param newFlights the new number of flights for the airport being edited
*/
template <typename T>
bool BinarySearchTree<T>::editFlight(Node<T>* currRoot, string targetCode, int newFlights)
{

    if (currRoot != nullptr)
    {
        bool temp = false;

        if(targetCode == currRoot->getItem().getIata())
        {
            cout << "Before Editing: ";
            cout << currRoot->getItem() << endl;
            T tempAirport = currRoot->getItem();
            tempAirport.setNumFlights(newFlights);
            currRoot->setItem(tempAirport);
            cout << "After Editing: " << currRoot->getItem() << endl;

            return true;
        }

        temp = editFlight(currRoot->left, targetCode, newFlights);
        if (temp == true)
        {
            return temp;
        }

        temp = editFlight(currRoot->right, targetCode, newFlights);
        if (temp == true)
        {
            return temp;
        }

    }
    else 
    {

        return false;

    }

}

/**
 * Edits an airport's number of freight in the BST.
 * @param currRoot the root of a BST
 * @param targetCode the IATA code of the airport to edit
 * @param newFreight the new number of freight for the airport being edited
*/
template <typename T>
bool BinarySearchTree<T>::editFreight(Node<T>* currRoot, string targetCode, int newFreight)
{

    if (currRoot != nullptr)
    {
        bool temp = false;

        if(targetCode == currRoot->getItem().getIata())
        {
            cout << "Before Editing: ";
            cout << currRoot->getItem() << endl;
            T tempAirport = currRoot->getItem();
            tempAirport.setFreight(newFreight);
            currRoot->setItem(tempAirport);
            cout << "After Editing: " << currRoot->getItem() << endl;

            return true;
        }

        temp = editFreight(currRoot->left, targetCode, newFreight);
        if (temp == true)
        {
            return temp;
        }

        temp = editFreight(currRoot->right, targetCode, newFreight);
        if (temp == true)
        {
            return temp;
        }

    }
    else
    {

        return false;

    }

}

/**
 * Edits an airport's number of passengers in the BST.
 * @param currRoot the root of a BST
 * @param targetCode the IATA code of the airport to edit
 * @param newPassengers the new number of passengers for the airport being edited
*/
template <typename T>
bool BinarySearchTree<T>::editPassengers(Node<T>* currRoot, string targetCode, int newPassengers)
{

    if (currRoot != nullptr)
    {
        bool temp = false;

        if(targetCode == currRoot->getItem().getIata())
        {
            cout << "Before Editing: ";
            cout << currRoot->getItem() << endl;
            T tempAirport = currRoot->getItem();
            tempAirport.setNumPassengers(newPassengers);
            currRoot->setItem(tempAirport);
            cout << "After Editing: " << currRoot->getItem() << endl;

            return true;
        }

        temp = editPassengers(currRoot->left, targetCode, newPassengers);
        if (temp == true)
        {
            return temp;
        }

        temp = editPassengers(currRoot->right, targetCode, newPassengers);
        if (temp == true)
        {
            return temp;
        }

    }
    else 
    {

        return false;

    }

}

#endif // BINARYSEARCHTREE_H
