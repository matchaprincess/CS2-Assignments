/** @file main-7.cpp * /
  * @author Valerie Williams
  * @date 2/17/2023
  * Program to test the methods defined in LinkedList.cpp
  */

#include <iostream>
#include "Node-2.cpp"
#include "LinkedList.cpp"

using namespace std;

/**
 * The purpose of this method is to test the methods defined in LinkedList.cpp
*/
int main(){

    LinkedList myList;

    //myList.insertAtHead(10);
    for (int i = 10; i <= 100; i+=10)
        myList.insertAtHead(i);


    myList.printList();

    if (myList.search(220))
        cout << "220 found" << endl;
    else
        cout << "220 not found" << endl;

    cout << myList.countElements_multiples(3) << endl;


    cout << myList.getSize() << endl;

    cout << "Removing 20..." << endl;
    myList.remove(20);

    cout << "-----------------------------" << endl;
    myList.printList();
    cout << myList.getSize() << endl;


    myList.insertAtTail(220);

    cout << "-----------------------------" << endl;

    myList.printList();

    cout << "-----------------------------" << endl;

    // testing newly added methods

    // testing getSize method
    cout << "Size after removing '20': " << myList.getSize() << endl;

    cout << "-----------------------------" << endl;

    // testing countFrequencyOf method
    cout << "Testing countFrequencyOf..." << endl;
    cout << "Frequency of 100: " << myList.countFrequencyOf(100) << endl;

    cout << "-----------------------------" << endl; 

    // testing displayFromFrontToN
    cout << "Testing displayFromFrontToN... n = 4" << endl; 
    myList.displayFromFrontToN(4);

    cout << "-----------------------------" << endl; 

    // testing searchVal
    cout << "Testing searchVal... searching for 100..." << endl;
    cout << "Was 100 found? T/F... " << boolalpha << myList.searchVal(100) << endl;

    cout << "-----------------------------" << endl;

    // testing displayFromNToEnd
    cout << "Testing displayFromNToEnd... n = 3" << endl;
    myList.displayFromNToEnd(3);

    cout << "-----------------------------" << endl;

    // testing fillListFromFile
    cout << "Filling from file: linkedListData1.txt" << endl;
    myList.fillListFromFile();

    // testing insertInOrder
    cout << "Inserting 20 in its proper order..." << endl;
    myList.insertInOrder(20);

    // testing displayInRows
    cout << "Testing displayInRows..." << "\n" << endl; 
    myList.displayInRows();

    // exit code
    return 0;

}














/*

Node *n = new Node(11, nullptr);

    cout << n->getData() << endl;

    Node *n2 = new Node(20, n);

    Node *temp;

    temp = n2;

    cout << temp->getData() << endl;

    temp = temp->getNext();

    cout << temp->getData() << endl;


    temp = temp->getNext();

    cout << temp << endl;

    cout << temp->getData() << endl;

    if (temp == nullptr)
        cout << "nullptr" << endl;

*/
