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
 * Displays the options for the main menu, gets the user's choice, and calls the appropriate menu function,
*/
void menu_Main(BinarySearchTree<Airport>* tree)
{

    // initialize the choice variable to store the user's choice
    int choice;

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
    cin >> choice;

    // validation
    while (choice < 1 || choice > 5)
    {
        cout << "Please enter a valid option 1-5: " << endl;
        cin >> choice;
    }

    // open the appropriate menu
    if (choice == 1) // search
    {
        menu_Search(tree);
    }
    else if (choice == 2) // reports
    {
        menu_Report(tree);
    }
    else if (choice == 3) // maximums, minimums
    {
        menu_MaxMin(tree);
    }
    else if (choice == 4) // edits
    {
        menu_Edit(tree);
    }
    else if (choice == 5) // exit 
    {
        cout << "Exiting the program..." << endl;
        exit(0);
    }


}

/**
 * Displays the options for the search menu, gets the user's choice, and runs the appropriate helper function.
*/
void menu_Search(BinarySearchTree<Airport>* tree)
{

    // initialize the choice variable to store the user's choice
    int choice;

    // display the sub menus
    cout << "✧˖°. Search Menu ✧˖°." << endl;
    cout << "Options: " << endl;
    cout << "[1] Search Airports by IATA Code" << endl;
    cout << "[2] Search Airports by State" << endl;
    cout << "[3] Search Airports by Minimum Passenger" << endl;
    cout << "[4] Return to Main Menu" << endl;

    // prompt user for choice & store it
    cout << "Please enter your choice: " << endl;
    cin >> choice;

    // validation
    while (choice < 1 || choice > 5)
    {
        cout << "Please enter a valid option 1-5: " << endl;
        cin >> choice;
    }

    // call the search methods
    if (choice == 1) // search by iata
    {
            // declare necessary variables
            string iataToSearch;

            // prompt user for the code they want to search for
            cout << "Please enter the IATA code: " << endl;
            cin >> iataToSearch;
            transform(iataToSearch.begin(), iataToSearch.end(), iataToSearch.begin(), ::toupper); // make the input upper case


            // display the airport
            tree->searchByCode(tree->getRoot(), iataToSearch);

            menu_Search(tree);
    }

    else if (choice == 2) // search by state
    {

            // declare necessary variables
            string stateToSearch;

            // prompt user for the code they want to search for
            cout << "Please enter the State: " << endl;
            cin >> stateToSearch;
            transform(stateToSearch.begin(), stateToSearch.end(), stateToSearch.begin(), ::toupper); // make the input upper case


            // display the airport
            tree->searchByState(tree->getRoot(), stateToSearch);

            menu_Search(tree);

    }

    else if (choice == 3) // search by min. passengers
    {

            // declare necessary variables
            string temp;
            int minPassengersToSearch;

            // prompt user for the code they want to search for
            cout << "Please enter the minimum passengers: " << endl;
            cin >> temp;
            minPassengersToSearch = stoi(temp);

            // display the airports
            tree->searchByMinPassenger(tree->getRoot(), minPassengersToSearch);

            menu_Search(tree);

    }

    else if (choice == 4)
    {
        menu_Main(tree);
    }


}

/**
 * Displays the options for the report menu, gets the user's choice, and runs the appropriate helper function.
*/
void menu_Report(BinarySearchTree<Airport>* tree)
{
    // initialize the choice variable to store the user's choice
    int choice;

    // display the sub menus
    cout << "✧˖°. Report Menu ✧˖°." << endl;
    cout << "Options: " << endl;
    cout << "[1] All Airports" << endl;
    cout << "[2] Airports by Average Passenger" << endl;
    cout << "[3] Airports by Average Flights" << endl;
    cout << "[4] Return to Main Menu" << endl;

    // prompt user for choice and store it
    cout << "Please enter your choice: " << endl;
    cin >> choice;

    // validation
    while (choice < 1 || choice > 5)
    {
        cout << "Please enter a valid choice 1-5: " << endl;
        cin >> choice;
    }

    // call the report methods
    if (choice == 1) // display all airports
    {
            // display the header
            // border
            cout << setfill('*') << setw(180) << "*" << endl;

            // header items
            cout << setfill(' ');
            cout << "Name" << setw(70) << "State" << setw(25) << "City" << setw(10) << "Code";
            cout << setw(15) << "Passengers" << setw(20) << "Flights" << setw(20) << "Freight" << endl;

            // border
            cout << setfill('*') << setw(180) << "*" << endl;

            // display each airport in table format
            tree->displayAllAirports(tree->getRoot());

            menu_Report(tree);
    }

    else if (choice == 2) // by average passengers
    {
            // display the header
            // header items
            cout << setfill(' ');
            cout << "Name" << setw(100) << "City" << setw(22) << "State" << setw(20) << "Code";
            cout << setw(24) << "Passengers" << endl;


            tree->averageDailyPassengers(tree->getRoot());

            menu_Report(tree);
    }

    else if (choice == 3) // by average flights per day
    {
            // header items
            cout << setfill(' ');
            cout << "Name" << setw(100) << "City" << setw(22) << "State" << setw(20) << "Code";
            cout << setw(24) << "Flights" << endl;

            tree->averageDailyFlights(tree->getRoot());

            menu_Report(tree);
    }

    else if (choice == 4)
    {
        menu_Main(tree);
    }

}

/**
 * Displays the options for the maximum-minimum menu, gets the user's choice, and runs the appropriate helper function.
*/
void menu_MaxMin(BinarySearchTree<Airport>* tree)
{
    // initialize the choice variable to store the user's choice
    int choice;

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
    cin >> choice;

    // validation
    while (choice < 1 || choice > 7)
    {
        cout << "Please enter a valid option 1-5: " << endl;
        cin >> choice;
    }

    // display the max + mins
    if (choice == 1) // maximum passengers
    {
        Airport temp = tree->maxObjByDataMember(tree->getRoot(), "numPassengers");
        cout << "Number of Passengers: " << temp.getNumPassengers() << endl;
        cout << "Airport Name: " << temp.getName() << endl;
        cout << "Airport Code: " << temp.getIata() << endl;

        menu_MaxMin(tree);

    }

    else if (choice == 2) // maximum freight
    {
        Airport temp = tree->maxObjByDataMember(tree->getRoot(), "freightInTons");
        cout << "Amount of Freight: " << temp.getFreight() << endl;
        cout << "Airport Name: " << temp.getName() << endl;
        cout << "Airport Code: " << temp.getIata() << endl;

        menu_MaxMin(tree);
    }

    else if (choice == 3) // maximum flights
    {
        Airport temp = tree->maxObjByDataMember(tree->getRoot(), "numFlights");
        cout << "Number of Flights: " << temp.getNumFlights() << endl;
        cout << "Airport Name: " << temp.getName() << endl;
        cout << "Airport Code: " << temp.getIata() << endl;

        menu_MaxMin(tree);

    }
    
    else if (choice == 4) // minimum passengers
    {
        Airport temp = tree->minObjByDataMember(tree->getRoot(), "numPassengers");
        cout << "Number of Passengers: " << temp.getNumPassengers() << endl;
        cout << "Airport Name: " << temp.getName() << endl;
        cout << "Airport Code: " << temp.getIata() << endl;

        menu_MaxMin(tree);
    }

    else if (choice == 5) // minimum freight
    {
        Airport temp = tree->minObjByDataMember(tree->getRoot(), "freightInTons");
        cout << "Amount of Freight: " << temp.getFreight() << endl;
        cout << "Airport Name: " << temp.getName() << endl;
        cout << "Airport Code: " << temp.getIata() << endl;

        menu_MaxMin(tree);

    }

    else if (choice == 6) // minimum flights
    {
        Airport temp = tree->minObjByDataMember(tree->getRoot(), "numFlights");
        cout << "Number of Flights: " << temp.getNumFlights() << endl;
        cout << "Airport Name: " << temp.getName() << endl;
        cout << "Airport Code: " << temp.getIata() << endl;

        menu_MaxMin(tree);
    }

    else if (choice == 7) // go back to main menu
    {   
        menu_Main(tree);
    }

}

/**
 * Displays the options for the edit menu, gets the user's choice, and runs the appropriate helper function.
*/
void menu_Edit(BinarySearchTree<Airport>* tree)
{
    // initialize the choice variable to store the user's choice
    int choice;

    // display the sub menus
    cout << "✧˖°. Edit Menu ✧˖°." << endl;
    cout << "Options: " << endl;
    cout << "[1] Edit Passengers" << endl;
    cout << "[2] Edit Freight" << endl;
    cout << "[3] Edit Flights" << endl;
    cout << "[4] Return to Main Menu" << endl;

    // prompt user for choice and store it
    cout << "Please enter your choice: " << endl;
    cin >> choice;
    
    // validation
    while (choice < 1 || choice > 5)
    {
        cout << "Please enter a valid option 1-5: " << endl;
        cin >> choice;
    }

    // edit the proper airport object
    if (choice == 1) // edit the number of passengers
    {
        // prompt user for the iata code of the airport to edit
        string code;
        cout << "Please enter the IATA code for the airport you would like to edit: " << endl;
        cin >> code;
        transform(code.begin(), code.end(),code.begin(), ::toupper); // make the input upper case

        // prompt user for the number of new passengers
        int new_Passengers;
        cout << "Please enter the number of new passengers for this airport: " << endl;
        cin >> new_Passengers;

        // new passengers cannot be negative
        while (new_Passengers < 0)
        {
            cout << "Number of passengers cannot be negative." << endl;
            cout << "Please enter the number of new passengers for this airport: " << endl;
            cin >> new_Passengers;
        }

        // edit and display before + after
        tree->editPassengers(tree->getRoot(), code, new_Passengers);

        menu_Edit(tree);
        
    }

    else if (choice == 2) // edit amount of freight
    {
        // prompt user for the iata code of the airport to edit
        string code;
        cout << "Please enter the IATA code for the airport you would like to edit: " << endl;
        cin >> code;
        transform(code.begin(), code.end(),code.begin(), ::toupper); // make the input upper case

        // prompt user for the number of new freight
        int new_Freight;
        cout << "Please enter the new number of freight for this airport: " << endl;
        cin >> new_Freight;

        // new freight cannot be negative
        while (new_Freight < 0)
        {
            cout << "Number of freight cannot be negative." << endl;
            cout << "Please enter the new number of freight for this airport: " << endl;
            cin >> new_Freight;
        }

        // edit and display before + after
        tree->editFreight(tree->getRoot(), code, new_Freight);

        // go back to the main menu
        menu_Edit(tree);

    }

    else if (choice == 3) // edit the number of flights
    {
        // prompt user for the iata code of the airport to edit
        string code;
        cout << "Please enter the IATA code for the airport you would like to edit: " << endl;
        cin >> code;
        transform(code.begin(), code.end(),code.begin(), ::toupper); // make the input upper case

        // prompt user for the number of new flights
        int new_Flights;
        cout << "Please enter the number of new flights for this airport: " << endl;
        cin >> new_Flights;

        // new flights cannot be negative
        while (new_Flights < 0)
        {
            cout << "Number of flights cannot be negative." << endl;
            cout << "Please enter the number of new flights for this airport: " << endl;
            cin >> new_Flights;
        }

        // edit and display before + after
        tree->editFlight(tree->getRoot(), code, new_Flights);

        menu_Edit(tree);

    }

    else if (choice == 4)
    {
        menu_Main(tree);
    }

}