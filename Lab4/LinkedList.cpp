/** @file LinkedList.cpp * /
  * @author Valerie Williams
  * @date 2/17/2023
  * Program to create and perform operations on a linked list
  * abstract data type.
  */

#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * Creates a LinkedList object with no parameters.
*/
LinkedList::LinkedList()
{
    head = nullptr;  //when instantiated, head is null
    numElements = 0;
}

/** 
 * Destroys a LinkedList object.
*/
LinkedList::~LinkedList()
{
    //dtor
}

/**
 * Inserts a new node at the head of the linked list.
*/
void LinkedList::insertAtHead(int newData)
{

    Node *n = new Node(newData, nullptr);

    n->setNext(head);

    head = n;

    numElements++;

}

/**
 * Prints the contents of a linked list to the console. 
*/
void LinkedList::printList()
{

    Node *temp;

    temp = head;

    while(temp != nullptr){

        cout << temp->getData() << endl;
        temp = temp->getNext();

    }

}

/**
 * Searches for a specified value in the linked list and returns true or false
 * depending if the specified value is in the list or not.
 * @param toFind the value to search for
 * @return true if toFind is in the list, false if toFind is not in the list
*/
bool LinkedList::search(int toFind)
{

    bool found = false;

    Node *temp;

    temp = head;

    while (temp != nullptr){   //use found as a condition to stop after one instance found
        if (temp->getData() == toFind)
            found = true;
        temp = temp->getNext();

    }//end while

    return found;

}

/**
 * Counts the number of instances for a specified multiple in the linked list.
 * @param multiple the multiple to test for
 * @return the count of instances for the multiple
*/
int LinkedList::countElements_multiples(int multiple)
{

    int count = 0;

    Node *temp;

    temp = head;

    while (temp != nullptr){
        if (temp->getData() % multiple == 0)
            count ++;
        temp = temp->getNext();
    }//end while

    return count;


}

/**
 * Returns the size of a linked list. 
 * @return the number of elements in the linked list
*/
int LinkedList::getSize()
{

    return numElements;

}

/**
 * Removes a specifc value from a linked list.
 * @param toRemove the value to remove from the list.
 * @return true if the value has been removed, false if it wasn't in the list
*/
bool LinkedList::remove(int toRemove)
{

    Node *temp, *prev;

    temp = head;

    bool found = false;

    if (temp != nullptr && temp->getData() == toRemove){
        head = temp->getNext();
        found = true;
    }
    else {
        while(temp !=  nullptr && temp->getData() != toRemove){ //traverse until end or element found
            prev = temp;
            temp = temp->getNext();

        }//end while

        if (temp !=  nullptr){
            prev->setNext(temp->getNext());
            found = true;
        }//end if



    }//end else

    if (found)
        numElements--;

    return found;

}

/**
 * Inserts a new node at the tail of the list.
 * @param toAdd the value to add to the tail of the list 
*/
void LinkedList::insertAtTail(int toAdd)
{

    Node *n = new Node(toAdd, nullptr);

    if (head == nullptr)
        head = n;

    else {
        Node *temp = head;
        while(temp->getNext() != nullptr){
            temp = temp->getNext();

        }
        temp->setNext(n);


    }//end else

    numElements++;

}


/**
 * Checks if a linked list is empty or not.
 * @return true if the linked list is empty, false if it's not empty
*/
bool LinkedList::isEmpty() 
{

    return (numElements == 0);

}

/**
 * Searches the linked list for a specified value.
 * @param item the item to search for
 * @return true if the item is in the list, false if it is not
*/
bool LinkedList::searchVal(int item)
{

    // declare necessary variables: found and currNode
    bool found = false;
    Node* curNode = head;

    // while we're in the list, check with an if statement if the current
    // node is equal to the item we're trying to find 
    while (curNode != nullptr)
    {

        if (curNode->getData() == item)
        {

            found = true;

        }

        // change the current node to the next node in the list
        curNode = curNode->getNext();

    }

    // return found
    return found;

}

/**
 * Counts the frequency of a specified item in the list.
 * @param item the item to count the frequency of
 * @return the frequency of the item
*/
int LinkedList::countFrequencyOf(int item)
{

    // declare necessary variables
    Node* curNode = head;
    int frequency = 0;

    // iterate through the list, checking if the current node is equal to the item
    // if it is, we can update the counter by 1
    while (curNode != nullptr)
    {

        if (curNode->getData() == item)
        {

            frequency++;

        }

        // move to the next node
        curNode = curNode->getNext();

    }

    // return the frequency 
    // note: returns 0 if the item isn't in the list
    return frequency;

}

/**
 * Displays the list from the first node to the nth node in the list.
 * @param n the 'index' of the node to end at
*/
void LinkedList::displayFromFrontToN(int n)
{

    // declare neccessary variables
    Node* curNode = head;
    int counter = 0;

    if (n <= numElements)
    {

        do{
        
            cout << curNode->getData() << endl;
            curNode = curNode->getNext();
            counter++;
        
        } while (counter != n);

    }
    else
    {

        cout << "N cannot be greater than the number of elements in the list." << endl;

    }

}

/**
 * Displays the list from the nth node in the list to the last node in the list.
 * @param n the 'index' of the node to start at
*/
void LinkedList::displayFromNToEnd(int n)
{

    // declare necessary variables: curNode and counter
    Node* curNode = head;
    int counter = 0;

    // validation to make sure n is a realistic number for the list
    if(n > numElements)
    {

        cout << "Error: n is greater than the number of elements in the list." << endl;

    }

    // get curNode to the nth element
    while (counter != n)
    {

        curNode = curNode->getNext();
        counter++;

    }

    // curNode is now at the nth value
    // start displaying values!
    while (curNode != NULL)
    {

        cout << curNode->getData() << endl;
        curNode = curNode->getNext();

    }

}

/**
 * Inserts a new node in the proper order [descending]
 * @param n the new node to insert into the linked list
*/
void LinkedList::insertInOrder(int n)
{
   
    // if n > head, insert at the head
    if (n > head->getData())
    {

        insertAtHead(n);

    }
    else
    {

        // declare necessary variables 
        Node* curNode = head;
        Node* prevNode = nullptr;
        Node* newItem = new Node(n, nullptr);


        // loop through the list comparing new note to each current element
        while(curNode != nullptr)
        {

            // inserting at tail
            if(curNode->getNext() == nullptr)
            {

                insertAtTail(n);
                curNode = nullptr;

            }
            else if (n > curNode->getNext()->getData())
            {

                newItem->setNext(curNode->getNext());
                curNode->setNext(newItem);
                curNode = nullptr;
                numElements++;
                
            }
            else
            {

                curNode = curNode->getNext();

            }

        }

    }

}

/**
 * Fills the linked list with data from a file (LinkedListData1.txt)
*/
void LinkedList::fillListFromFile()
{
    // declare necessary variables 
    ifstream myFile;
    int curLine;
    Node* curNode;
    Node* preNode;

    // open the file 
    myFile.open("linkedListData1.txt");

    // prints an error message if there is trouble opening the file
    if(!myFile.is_open())
    {

        cout << "Error with opening file linkedListData1.txt" << endl;

    }

    // loop through the file and add each line of data to the list
    while(!myFile.eof())
    {
        // read data into curLine
        myFile >> curLine;

        // insert into the list in order
        insertInOrder(curLine);

    }

    // close the file 
    myFile.close();

}

/**
 * Displays the linked list in rows of 10. 
*/
void LinkedList::displayInRows()
{
    // declare necessary variables
    int counter = 0;
    Node* curNode = head;

    while (counter <= numElements && curNode != nullptr)
    {

        cout << curNode->getData() << " " << flush;
        counter++;
        curNode = curNode->getNext();

        if(counter % 10 == 0)
        {

            cout << "\n" << endl;
            
        }

    }    

}

