#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "QueueInterface.h"
#include <iostream>

using namespace std;

const int MAX_CAPACITY = 5;

template<typename T>
class ArrayQueue : public QueueInterface<T> {
    public:
        ArrayQueue() ;
        ~ArrayQueue() ;

        bool isEmpty() ;
        bool dequeue() ;
        bool enqueue(T );
        T peek() ;
        int size();





    private:
        int numItems;
        T items[MAX_CAPACITY];
        int front;
        int back;



};

#endif // ARRAYQUEUE_H





template<typename T>
ArrayQueue<T>::ArrayQueue(){

    numItems = 0;
    front = -1;
    back = -1;
}




template<typename T>
ArrayQueue<T>::~ArrayQueue(){
    //destructor code
}



template<typename T>
bool ArrayQueue<T>::isEmpty(){
    return numItems == 0;

    //return front == back == -1;
}





template<typename T>
bool ArrayQueue<T>::dequeue(){
    bool ableToDequeue = false;


    if (front == -1 && back == -1){
        cout << "queue is empty... " << endl;

    }
        //only one element
    else if (front == back){
        ableToDequeue = true;
        front = back = -1;
        numItems--;
    }

    else {
        front = (front + 1) % MAX_CAPACITY;
        ableToDequeue = true;
        numItems--;
    }

    return ableToDequeue;
}





template<typename T>
bool ArrayQueue<T>::enqueue(T newItem){

    bool ableToEnqueue = false;

    //empty queue
    if (back == -1 && front == -1){
        front = back = 0;
        ableToEnqueue = true;
        items[back] = newItem;
        numItems++;

    }
    else if (((back + 1) % MAX_CAPACITY) == front){
        cout << "queue is full... " << endl;
    }
    else{
        back = (back + 1) % MAX_CAPACITY;
        items[back] = newItem;
        ableToEnqueue = true;
        numItems++;
    }

    return ableToEnqueue;



}//end enqueue()





template<typename T>
T ArrayQueue<T>::peek(){

    return items[front];

}





template<typename T>
int ArrayQueue<T>::size(){

    return numItems;
}


/*
template<typename T>
void ArrayQueue<T>::display(){
    int i = front;

    if (front == -1 && back == -1)
        cout << "queue is empty..." << endl;


    else {
        cout << "queue elements: " ;
        while (i != back){
            cout << items[i] << " " ;
            i = (i + 1) % MAX_CAPACITY;
        }
        cout << items[back] << endl;


    }
}

*/
