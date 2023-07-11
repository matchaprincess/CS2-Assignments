#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node-2.h"


class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void insertAtHead(int);
        void printList();
        bool search(int);
        int countElements_multiples(int);
        bool remove(int);
        int getSize();
        void insertAtTail(int);
        bool isEmpty();
        bool searchVal(int item);
        int countFrequencyOf(int item);
        void displayFromFrontToN(int n);
        void displayFromNToEnd(int n);
        void insertInOrder(int n);
        void fillListFromFile();
        void displayInRows();



    private:
        Node *head;
        int numElements;
};

#endif // LINKEDLIST_H
