/** @file main.cpp * /
* @author Valerie Williams
* @date 4/4/2023
* @version 1
* Program to perform operations on information about airports in the United States.
*/

#include "Airport.h" // to use the airport class
#include "airportMenu.h" // to use the airport menu class
#include "BinarySearchTree.h" // to use a binary search tree
#include <string> // for using strings
#include <iostream> // for input and output
#include <fstream> // to use files

using namespace std;

/**
 * The purpose of this main function is to allow a user to populate a binary search tree of Airport objects
 * from a CSV file containing data about airports and to perform operations on that data.
*/
int main()
{

    // declare necessary variables and objects
    BinarySearchTree<Airport>* airportTree = new BinarySearchTree<Airport>(); // the binary tree of airports
    Airport airportsToAdd[36]; // the airports to add
    fstream myFile; // the csv file with all the airport data 
    string toRead; // the line of data to read from the csv file
    int counter = 0; // counter for the index of the array
    int choice; // the user's choice from the menu
    
    // create a binary tree from the csv file

    // open the file
    myFile.open("us-airports-1.csv");

    // skip the first line because it contains header information
    getline(myFile, toRead);

    // loop through the file
    while (!myFile.eof())
    {
        
        // get the current line from the file
        getline(myFile, toRead);

        // if the line isn't empty, create an object from it and add it to the array
        if (!toRead.empty())
        {
            // airport object from the line
            Airport currentAirport(toRead);

            // add it to the airport array
            airportsToAdd[counter] = currentAirport;
        }

        // update the counter
        counter++;
        
    }

    // populate the binary tree with the airport data
    airportTree->loadTreeData(airportsToAdd, counter);

    // display main menu & collect user choice
    menu_Main(airportTree);

    return EXIT_SUCCESS;

}




