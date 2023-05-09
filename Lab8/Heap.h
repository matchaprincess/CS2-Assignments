#ifndef HEAP_H
#define HEAP_H

#include "HeapInterface.h"

class Heap : public HeapInterface {
    public:
        Heap();

        ~Heap();

        //interface methods
        bool remove();
        bool add(int );
        int getHeapSize() const;
        int peek() const;
        bool isEmpty() const;
        void clear();

        void displayHeap();


    private:

        static const int CAPACITY = 5000;

        int itemCount = 0;

        void percolateDown(int currentNode);


        int getParent(int currentNode) const;
        int getRightChild(int currentNode) const;
        int getLeftChild(int currentNode) const;

        bool isLeaf(int currentNode) const;


        int *heapArray;  //a pointer to an array of integers - so that we can use swap()

};

#endif // HEAP_H
