/** @file MyArray.h * /
  * @author Valerie Williams
  * @date 2/10/2023
  * Header file specifying an array data type and various methods to perform operations 
  * on the data within each array. 
  */

#ifndef MYARRAY_H
#define MYARRAY_H

#include "Computational.h"
#include <stddef.h>
#include <array> 

using namespace std;

template <typename T> //<class T>
class MyArray : public Computational<T>
{
    public:
        MyArray();
        MyArray(T []);

        void displayArray();
        T maximumElement();
        int countElements(T toCount);
        void printReverse();
        void increaseElementsBy(T toIncrease);
        bool find(T toFind);
        bool isFull();
        void add(T toAdd);
        void removeLast();
        void remove(T toRemove);


    private:
        T theArray[10];
        int size; 

};


/**
 * The default constructor creates a MyArray with a maximum of ten elements with each
 * element being set to 0. 
*/
template <typename T>
MyArray<T>::MyArray ()
{

    size = 0;

    for (int i = 0; i < 10; i++)
    {

        theArray[i] = 0;
        size++;

    }

}

/**
 * The overloaded constructor allows a user to create a MyArray from 
 * an existing array.
 * @param arr The array to be copied into a MyArray object
*/
template <typename T>
MyArray<T>::MyArray(T arr[])
{
    size = 0; 

    for (int i = 0; i < 10; i++){

        theArray[i] = arr[i];
        size++;

    }
}

/**
 * Displays all elements of the MyArray to the output stream.
*/
template <typename T>
void MyArray<T>::displayArray()
{
    for (int i = 0; i < size; i++)
    {

        cout << "[" << i << "] = " << theArray[i] << endl;

    }

}

/**
 * Returns the maximum element in a MyArray.
 * @returns T the maximum element
*/
template<typename T>
T MyArray<T>::maximumElement()
{
    T max = theArray[0];

    for (int i = 1; i < size; i++)
    {

        if (theArray[i] > max)
        {

            max = theArray[i];

        }

    }
        
    return max;

}

/**
 * Returns the number of occurrences in the MyArray of a given value.
 * @param toCount the value to count the occurrences of
 * @return the number of times toCount occurrs in the MyArray
*/
template <typename T> //<class T>
int MyArray<T>::countElements(T toCount) 
{

    int tCount = 0;

    for (int i = 0; i < size; i++)
    {

        if (theArray[i] == toCount) 
        {

            tCount++;

        }

    }

    return tCount;

}

/**
 * Prints the elements of a MyArray to the output stream in reverse order. 
*/
template <typename T> //<class T>
void MyArray<T>::printReverse() 
{

    for (int i = size-1; i >= 0; i--)
    {

        cout << "[" << i << "] = " << theArray[i] << endl;

    }

}

/**
 * Increases the value of each element by a specific value.
 * @param toIncrease the value to increase each element in the MyArray by
*/
template <typename T> //<class T>
void MyArray<T>::increaseElementsBy(T toIncrease)
{

    for(int i = 0; i < size; i++)
    {

        theArray[i] = theArray[i] + toIncrease;

    }

}

/**
 * Determines if a value exists in the MyArray.
 * @param toFind the value to search for
 * @return true if value is found, false if value is not found
*/
template <typename T> //<class T>
bool MyArray<T>::find(T toFind)
{

    bool found = false;

    for (int i = 0; i < size; i++)
    {
        
        if (theArray[i] == toFind)
        {

            found = true;

        }

    }

    return found; 

}

/**
 * Determines if a MyArray has the maximum number of elements (10) or not.
 * @return true if the array has 10 elements, false if it does not
*/
template <typename T> //<class T>
bool MyArray<T>::isFull()
{

    bool full = false;

    if(size == 10)
    {

        full = true;

    }

    return full;

}

/**
 * Adds a specific element to the end of the MyArray.
 * @param toAdd the element to add to the array
*/
template <typename T> //<class T>
void MyArray<T>::add(T toAdd)
{

    int index = size;

    if (!isFull())
    {

        theArray[index] = toAdd;
        size++;

    }


}

/**
 * Removes the last element of a MyArray.
*/
template <typename T> //<class T>
void MyArray<T>::removeLast()
{

    theArray[size-1] = 0; 
    size--;

}

/**
 * Removes all occurrences of a specific value from the MyArray.
 * @param toRemove the value to remove from the array
*/
template <typename T> //<class T>
void MyArray<T>::remove(T toRemove)
{
    int currentIndex = -1;

    for (int i = 0; i < size; i++)
    {

        if (theArray[i] == toRemove)
        {

            currentIndex = i; 
            theArray[i] = 0;
            size--;

        }

        if (currentIndex != -1)
        {

            for(int j = 0; j < size; j++)
            {

                theArray[j] = theArray[j+1];

            }

            currentIndex = -1;

        }

    }

}

#endif // MYARRAY_H