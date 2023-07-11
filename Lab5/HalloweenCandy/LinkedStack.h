#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "Stack_Interface.h"
#include "Node.h"

template<typename T>
class LinkedStack : public Stack_Interface<T>
{
    public:
        LinkedStack();
        ~LinkedStack();

        bool isEmpty() ;
        bool push(const T&) ;
        bool pop() ;
        T peek() ;


    private:
        Node<T> *head;


};

#endif // LINKEDSTACK_H


template<typename T>
LinkedStack<T>::LinkedStack(){
    head = nullptr;
}


template<typename T>
LinkedStack<T>::~LinkedStack(){
    //destructor
}


template<typename T>
bool LinkedStack<T>::isEmpty(){
    return (head == nullptr);
}



template<typename T>
bool LinkedStack<T>::push(const T& newData){

    Node<T> *n = new Node<T> (newData, nullptr);

    n->setNext(head);

    head = n;

    return true; //always returning true for a linked stack
}



template<typename T>
T LinkedStack<T>::peek(){

    return head->getData();
}




template<typename T>
bool LinkedStack<T>::pop(){

    bool popped = false;

    if (!isEmpty()){
        Node<T>* nodeToDeletePtr = head;
        head = head->getNext();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr; //MUST be deleted
        nodeToDeletePtr = nullptr;

        popped = true;
    }

    return popped;
}
