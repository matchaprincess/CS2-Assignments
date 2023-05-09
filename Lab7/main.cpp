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
    choice = menu_Main();


    // SEARCH
    if (choice == 1)
    {
        // store the user's Search menu choice
        int subchoice = menu_Search();

        // search by iata
        if (subchoice == 1)
        {
            // declare necessary variables
            string iataToSearch;

            // prompt user for the code they want to search for
            cout << "Please enter the IATA code: " << endl;
            cin >> iataToSearch;

            // display the airport
            airportTree->searchByCode(airportTree->getRoot(), iataToSearch);
        }

        // search by state
        if (subchoice == 2)
        {

            // declare necessary variables
            string stateToSearch;

            // prompt user for the code they want to search for
            cout << "Please enter the State: " << endl;
            cin >> stateToSearch;

            // display the airport
            airportTree->searchByState(airportTree->getRoot(), stateToSearch);
        }

        // search by minimum number of passengers
        if (subchoice == 3)
        {

            // declare necessary variables
            string temp;
            int minPassengersToSearch;

            // prompt user for the code they want to search for
            cout << "Please enter the minimum passengers: " << endl;
            cin >> temp;
            minPassengersToSearch = stoi(temp);

            // display the airports
            airportTree->searchByMinPassenger(airportTree->getRoot(), minPassengersToSearch);

        }

        // return to the main menu
        if (subchoice == 4)
        {
            menu_Main();
        }

    }

    // REPORTS
    if (choice == 2)
    {

        // store the user's report menu choice
        int subchoice = menu_Report();

        // report of all airports
        if (subchoice == 1)
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
            airportTree->displayAllAirports(airportTree->getRoot());

        }

        // report of average daily passengers
        if (subchoice == 2)
        {

            // display the header

            // header items
            cout << setfill(' ');
            cout << "Name" << setw(100) << "City" << setw(22) << "State" << setw(20) << "Code";
            cout << setw(24) << "Passengers" << endl;


            airportTree->averageDailyPassengers(airportTree->getRoot());

        }

        // report of average daily flights
        if (subchoice == 3)
        {
            // display the header
            
            // header items
            cout << setfill(' ');
            cout << "Name" << setw(100) << "City" << setw(22) << "State" << setw(20) << "Code";
            cout << setw(24) << "Flights" << endl;

            airportTree->averageDailyFlights(airportTree->getRoot());
        }

        // return to the main menu
        if (subchoice == 4)
        {
            menu_Main();
        }
    }

    // MAXIMUMS AND MINIMUMS
    if (choice == 3)
    {

        // store the user's max-min menu choice
        int subchoice = menu_MaxMin();

        // display airport with the maximum number of passengers
        if (subchoice == 1)
        {

            Airport temp = airportTree->maxObjByDataMember(airportTree->getRoot(), "numPassengers");
            cout << "Number of Passengers: " << temp.getNumPassengers() << endl;
            cout << "Airport Name: " << temp.getName() << endl;
            cout << "Airport Code: " << temp.getIata() << endl;

        }

        // display airport with the maximum amount of freight
        if (subchoice == 2)
        {

            Airport temp = airportTree->maxObjByDataMember(airportTree->getRoot(), "freightInTons");
            cout << "Amount of Freight: " << temp.getFreight() << endl;
            cout << "Airport Name: " << temp.getName() << endl;
            cout << "Airport Code: " << temp.getIata() << endl;

        }

        // display airport with the maximum number of flights
        if (subchoice == 3)
        {

            Airport temp = airportTree->maxObjByDataMember(airportTree->getRoot(), "numFlights");
            cout << "Number of Flights: " << temp.getNumFlights() << endl;
            cout << "Airport Name: " << temp.getName() << endl;
            cout << "Airport Code: " << temp.getIata() << endl;

        }

        // display airport with the minimum number of passengers
        if (subchoice == 4)
        {

            Airport temp = airportTree->minObjByDataMember(airportTree->getRoot(), "numPassengers");
            cout << "Number of Passengers: " << temp.getNumPassengers() << endl;
            cout << "Airport Name: " << temp.getName() << endl;
            cout << "Airport Code: " << temp.getIata() << endl;

        }

        // display airport with the minimum amount of freight
        if (subchoice == 5)
        {

            Airport temp = airportTree->minObjByDataMember(airportTree->getRoot(), "freightInTons");
            cout << "Amount of Freight: " << temp.getFreight() << endl;
            cout << "Airport Name: " << temp.getName() << endl;
            cout << "Airport Code: " << temp.getIata() << endl;

        }

        // display airport with the minimum number of flights
        if (subchoice == 6)
        {

            Airport temp = airportTree->minObjByDataMember(airportTree->getRoot(), "numFlights");
            cout << "Number of Flights: " << temp.getNumFlights() << endl;
            cout << "Airport Name: " << temp.getName() << endl;
            cout << "Airport Code: " << temp.getIata() << endl;

        }

        // return to the main menu
        if (subchoice == 7)
        {
            menu_Main();
        }
    }

    // EDITS
    if (choice == 4)
    {

        // store the user's choice for the edit menu
        int subchoice = menu_Edit();

        // editing the number of passengers
        if (subchoice == 1)
        {
            // prompt user for the iata code of the airport to edit
            string code;
            cout << "Please enter the IATA code for the airport you would like to edit: " << endl;
            cin >> code;

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
            airportTree->editPassengers(airportTree->getRoot(), code, new_Passengers);
        }

        // editing the amount of freight
        if (subchoice == 2)
        {

            // prompt user for the iata code of the airport to edit
            string code;
            cout << "Please enter the IATA code for the airport you would like to edit: " << endl;
            cin >> code;

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
            airportTree->editFreight(airportTree->getRoot(), code, new_Freight);

        }

        // editing the number of flights
        if (subchoice == 3)
        {

            // prompt user for the iata code of the airport to edit
            string code;
            cout << "Please enter the IATA code for the airport you would like to edit: " << endl;
            cin >> code;

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
            airportTree->editFlight(airportTree->getRoot(), code, new_Flights);

        }

        if (subchoice == 4)
        {
            menu_Main();
        }
        
    }

    return EXIT_SUCCESS;

}




