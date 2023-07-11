/** @file main.cpp * /
  * @author Valerie Williams
  * @date 3/12/2023
  * @version 1
  * Program to load car model data from a csv file into a queue data structure and
  * allow a user to delete all instances of a specified car from the queue. 
  */

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "ArrayQueue.h"
#include "LinkedQueue.h"

using namespace std;

// function declaration
bool caseInsensitiveCompare(string string1, string string2);

/**
 * The purpose of this program is to load car models into a queue and allow a user
 * to delete all instances of a specified car from the queue. The program allows
 * the user to do this as many times as they would like, as long as the queue is not 
 * empty.
*/
int main()
{

    // declare necessary variables
    fstream myFile; // to open and use file for car data
    LinkedQueue<string> carQueue; // the primary queue
    LinkedQueue<string> carQueue2; // the placeholder queue
    char repeat; // holds user's answer to repeating the program or not
    string toRead; // the string to read from the file
    string toAdd; // the string to actually add to the queue
    string currentElement; // the current element of the queue
    string key; // the element to delete from the queue


    // load data into queue 
    myFile.open("carMake.csv");

    // skip the first line (the csv file header)
    getline(myFile, toRead);

    // while loop to continue until end of file
    while (!myFile.eof())
    {

        // read the line into placeholder variable toRead
        getline(myFile, toRead);

        // if the string isn't empty, add it to the queue
        if (!toRead.empty())
        {
            toAdd = toRead.substr(0, toRead.find("\r"));
            carQueue.enqueue(toAdd);
        }

    }

    // close the file
    myFile.close();

    // the main functionality of the program
    do 
    {

        // display the current elements in the queue
        cout << "The queue current contains these elements: " << endl;
        while (!carQueue.isEmpty())
        {

            currentElement = carQueue.peek();
            cout << currentElement << endl;
            carQueue2.enqueue(currentElement);
            carQueue.dequeue();

        }

        // rebuild the queue so we can perform operations
        while(!carQueue2.isEmpty())
        {
            currentElement = carQueue2.peek();
            carQueue.enqueue(currentElement);
            carQueue2.dequeue();
        }

        // found is automatically false at first
        bool found = false;

        // prompt user for the key (the element to delete)
        cout << "Please enter the car you wish to delete: " << endl;
        getline(cin, key);

        cout << "Removing " << key << " from the queue..." << endl;

        // iterate through the queue and handle the main bulk of the logic
        while(!carQueue.isEmpty())
        {
            // set the current element to the top of the queue
            currentElement = carQueue.peek();

            // case: if the currentElement is what the user wants to delete
            if (caseInsensitiveCompare(currentElement, key))
            {
                found = true;
            }
            // case: if the currentElement is NOT what the user wants to delete
            else
            {
                carQueue2.enqueue(currentElement);
            }

            // dequeue the element we just compared
            carQueue.dequeue();

        }

        // transfer the new, updated queue data from the placeholder to the original queue
        while(!carQueue2.isEmpty())
        {
            currentElement = carQueue2.peek();
            carQueue.enqueue(currentElement);
            carQueue2.dequeue();
        }

        // let the user know if the element was not found in the queue
        if (found == false)
        {
            cout << "The item was not found..." << endl;
        }

        // display all the elements in the queue after the operation
        cout << "The queue contains: " << endl;

        while (!carQueue.isEmpty())
        {

            currentElement = carQueue.peek();
            cout << currentElement << endl;
            carQueue2.enqueue(currentElement);
            carQueue.dequeue();

        }

        // ask the user if they want to remove another one and repeat the process if yes 
        cout << "Remove another element? y/n" << endl;
        cin >> repeat;

        // recreate the queue for reuse if the user wants to remove another element
        if (repeat == 'Y' || 'y')
        {
            while(!carQueue2.isEmpty())
            {
                currentElement = carQueue2.peek();
                carQueue.enqueue(currentElement);
                carQueue2.dequeue();
            }

        }

    } while(repeat == 'Y' || repeat == 'y');

    // exit code
    return 0;
    
}

/**
 * The purpose of this method is to do a case-insensitive comparison of two strings.
 * @param string1 the first string to compare
 * @param string2 the second string to compare
 * @return true if the strings match (regardless of case), false if not
*/
bool caseInsensitiveCompare(string string1, string string2)
{

    bool equal = false; 

    // convert both strings to lowercase
    // converting string1 to lowercase
    for(int i = 0; i < string1.size(); i++)
    {
        string1[i] = tolower(string1[i]);
    }

    // converting string2 to lowercase
    for(int i = 0; i < string2.size(); i++)
    {
        string2[i] = tolower(string2[i]);
    }

    // if equal, return true. if not, return false.
    if (string1 == string2)
    {
        equal = true;
    }

    return equal;

}