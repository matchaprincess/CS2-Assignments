#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "Stack_Interface.h"
#include <cassert>

using namespace std;

const int MAX_ELEMENTS = 10;

template <typename T>
class ArrayStack : public Stack_Interface<T>
{
    public:
        ArrayStack();
        //virtual ~ArrayStack();
        bool isEmpty();
        bool push(const T&newItem);
        bool pop();
        T peek() ;
        void display();

        //bool isFull();


    private:
        T theStack[MAX_ELEMENTS];
        int top;
};

#endif

template <typename T>
ArrayStack<T>::ArrayStack(){
    top = -1; //index 0 will be the top of the stack, this could easily be MAX_ELEMENTS and the top would be the end of the array
}


template <typename T>
bool ArrayStack<T>::isEmpty(){

    return top == -1; //< 0
}


template <typename T>
bool ArrayStack<T>::push(const T&newItem){
    bool okToPush = false;
    if (top < MAX_ELEMENTS - 1){
        top++;
        theStack[top] = newItem;
        okToPush = true;
    }//end if

    return okToPush;

}



template <typename T>
bool ArrayStack<T>::pop(){

    bool popped = false;

    if (!isEmpty()){
        top--;
        popped = true;

    }

    return popped;
}



template<typename T>
T ArrayStack<T>::peek() {
    assert(!isEmpty());  //if the argument to assert is FALSE, message written to standard error and program terminated

    return theStack[top];

}

/**
 * The purpose of this method is to display a stack without altering any of its elements;
 * this is needed in order to be able to do arithmetic with the symbols after displaying.
*/
template<typename T>
void ArrayStack<T>::display()
{

    T current;

    // check if the stack is empty, exit the method
    // serves as the base case as this method is recursive
    if (this->isEmpty())
    {
        return;
    }

    // set the current variable to the current element
    current = this->peek();

    // pop the current element
    this->pop();

    // display the current element
    cout << current << endl;

    // call the method again
    this->display();

    // push element back onto stack
    this->push(current);

}

