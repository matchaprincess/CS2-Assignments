#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Node.h"
#include "QueueInterface.h"


template <typename T>
class LinkedQueue : public QueueInterface<T> {
    public:
        LinkedQueue();
        ~LinkedQueue();

         bool isEmpty() ;
         bool dequeue() ;
         bool enqueue(T ) ;
         T peek() ;

    private:
        Node<T> *front;  //head
        Node<T> *back;  //tail, rear

};

#endif // LINKEDQUEUE_H



template <typename T>
LinkedQueue<T>::LinkedQueue(){
    front = nullptr;
    back = nullptr;
}


template <typename T>
LinkedQueue<T>::~LinkedQueue(){

    //destructor code
}



template <typename T>
bool LinkedQueue<T>::isEmpty(){
    return front == nullptr && back == nullptr;
}



template <typename T>
bool LinkedQueue<T>::enqueue(T newItem){
    //insert at back
    Node<T> * newNode  = new Node<T>(newItem, nullptr);

    if (isEmpty()){
        front = newNode;
    }
    else{
        back->setNext(newNode);
    }

    back = newNode;

    return true; //it's always ok to add to a linked queue
}



template <typename T>
bool LinkedQueue<T>::dequeue(){
    bool ableToDequeue = false;

    if (!isEmpty()){
        //remove at front --- like pop in LinkedStack
        Node<T> * n = front;
        if (front == back){
            front = nullptr;
            back = nullptr;
        }
        else {
            front = front->getNext();
        }

        n->setNext(nullptr);
        delete n;
        n = nullptr;

        ableToDequeue = true;
    }//end if

    return ableToDequeue;
}


template <typename T>
T LinkedQueue<T>::peek(){
    return front->getData();
}