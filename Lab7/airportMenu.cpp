/** @file main.cpp * /
* @author Valerie Williams
* @date 4/4/2023
* @version 1
* A class to allow users to create binary search trees.
*/

#include "airportMenu.h"
#include "Airport.h"
#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream> // for use of input/output functionality
#include <string> // for use of strings
#include <sstream> // for use of the stringstream object + functionality for parsing data

using namespace std;


// Main menus

/**
 * Displays the options for the main menu, gets the user's choice, and returns it.
 * @return the user's choice from the menu options
*/
int menu_Main()
{
    // initialize the choice variable to store the user's choice
    string temp;
    int choice = 0;

    // display the sub menus
    cout << "Main Menu" << endl;
    cout << "Options: " << endl;
    cout << "[1] Search" << endl;
    cout << "[2] Reports" << endl;
    cout << "[3] Maximum/Minimums" << endl;
    cout << "[4] Edit" << endl;
    cout << "[5] Quit" << endl;

    // prompt user for choice & store it
    cout << "Please enter your choice: " << endl;
    cin >> temp;
    choice = stoi(temp);

    // error check 
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
    {
        cout << "Invalid entry. Must be a number 1-5.";
        cout << "Please enter your choice: " << endl;
        cin >> temp;
        choice = stoi(temp);
    } 

    // return the user's choice
    return choice;

}

/**
 * Displays the options for the search menu, gets the user's choice, and returns it.
 * @return the user's choice from the menu options
*/
int menu_Search()
{
    // initialize the choice variable to store the user's choice
    string temp;
    int choice = 0;

    // display the sub menus
    cout << "✧˖°. Search Menu ✧˖°." << endl;
    cout << "Options: " << endl;
    cout << "[1] Search Airports by IATA Code" << endl;
    cout << "[2] Search Airports by State" << endl;
    cout << "[3] Search Airports by Minimum Passenger" << endl;
    cout << "[4] Return to Main Menu" << endl;

    // prompt user for choice & store it
    cout << "Please enter your choice: " << endl;
    cin >> temp;
    choice = stoi(temp);

    // error check
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {

        cout << "Invalid entry. Must be a number 1-4." << endl;
        cout << "Please enter your choice: " << endl;
        cin >> choice; 

    }

    // return the user's choice
    return choice;

}

/**
 * Displays the options for the report menu, gets the user's choice, and returns it.
 * @return the user's choice from the menu options
*/
int menu_Report()
{
    // initialize the choice variable to store the user's choice
    string temp;
    int choice = 0;

    // display the sub menus
    cout << "✧˖°. Report Menu ✧˖°." << endl;
    cout << "Options: " << endl;
    cout << "[1] All Airports" << endl;
    cout << "[2] Airports by Average Passenger" << endl;
    cout << "[3] Airports by Average Flights" << endl;
    cout << "[4] Return to Main Menu" << endl;

    // prompt user for choice and store it
    cout << "Please enter your choice: " << endl;
    cin >> temp;
    choice = stoi(temp);

    // error check
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {

        cout << "Invalid entry. Must be a number 1-4." << endl;
        cout << "Please enter your choice: " << endl;
        cin >> choice;
        choice = stoi(temp); 

    }

    // return the user's choice
    return choice;

}

/**
 * Displays the options for the maximum-minimum menu, gets the user's choice, and returns it.
 * @return the user's choice from the menu options
*/
int menu_MaxMin()
{
    // initialize the choice variable to store the user's choice
    string temp;
    int choice = 0;

    // display the sub menus
    cout << "✧˖°. Max-Min Menu ✧˖°." << endl;
    cout << "Options: " << endl;
    cout << "[1] Display Airport with Max Passengers" << endl;
    cout << "[2] Display Airport with Max Freight" << endl;
    cout << "[3] Display Airport with Max Flights" << endl;
    cout << "[4] Display Airport with Min Passengers" << endl;
    cout << "[5] Display Airport with Min Freight" << endl;
    cout << "[6] Display Airport with Min Flights" << endl;
    cout << "[7] Return to Main Menu" << endl;

    // prompt user for choice and store it
    cout << "Please enter your choice: " << endl;
    cin >> temp;
    choice = stoi(temp);

    // error check
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5
        && choice != 6 && choice != 7)
    {

        cout << "Invalid entry. Must be a number 1-7." << endl;
        cout << "Please enter your choice: " << endl;
        cin >> choice; 
        choice = stoi(temp);

    }

    // return the user's choice
    return choice;
   
}

/**
 * Displays the options for the edit menu, gets the user's choice, and returns it.
 * @return the user's choice from the menu options
*/
int menu_Edit()
{
    // initialize the choice variable to store the user's choice
    string temp;
    int choice = 0;

    // display the sub menus
    cout << "✧˖°. Edit Menu ✧˖°." << endl;
    cout << "Options: " << endl;
    cout << "[1] Edit Passengers" << endl;
    cout << "[2] Edit Freight" << endl;
    cout << "[3] Edit Flights" << endl;
    cout << "[4] Return to Main Menu" << endl;

    // prompt user for choice and store it
    cout << "Please enter your choice: " << endl;
    cin >> temp;
    choice = stoi(temp);

    // error check
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {

        cout << "Invalid entry. Must be a number 1-4." << endl;
        cout << "Please enter your choice: " << endl;
        cin >> choice; 
        choice = stoi(temp);

    }

    // return the user's choice
    return choice;

}