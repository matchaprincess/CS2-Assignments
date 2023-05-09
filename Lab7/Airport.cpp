/** @file Airport.cpp * /
* @author Valerie Williams
* @date 4/4/2023
* @version 1
* A class that represents Airports and holds data about them.
*/

// import necessary libraries and files
#include "Airport.h" // include the header file with the declarations of variables, functions, etc
#include <iostream> // for use of input/output functionality
#include <string> // for use of strings
#include <sstream> // for use of the stringstream object + functionality for parsing data
#include <iomanip>


using namespace std;

// constructors

/**
 * The default constructor for an airport object creates an
 * airport object with all attributes set to null or 0.
*/
Airport::Airport()
{

    name = "";
    state = "";
    city = "";
    iata_code = "";
    numPassengers = 0;
    numFlights = 0;
    freightInTons = 0;

}

/**
 * This overloaded constructor for an airport object creates
 * an airport object from the specified string.
 * @param airportData a string containing all attributes of an airport
 *                    separated by commas.
*/
Airport::Airport(string a)
{
    // create the placeholder variables
    string name = ""; // name
    string state = "";
    string city = ""; // city
    string iata = ""; // iata code
    string passengers = ""; // num passengers
    string flights = ""; // num flights
    string tons = ""; // freight in tons

    // create the stringstream object that will help with parsing
    stringstream ss(a);

    // if the parameter string isn't empty...
    if (!a.empty())
    {

        // parse out the string to get what we need
        getline(ss, name, ',');
        getline(ss, state, ',');
        getline(ss, city, ',');
        getline(ss, iata, ',');
        getline(ss, passengers, ',');
        getline(ss, flights, ',');
        getline(ss, tons, '\r');

        // set the attributes from the parsed data
        this->name = name;
        this->city = city;
        this->state = state;
        this->iata_code = iata;
        this->numPassengers = stoi(passengers);
        this->numFlights = stoi(flights);
        this->freightInTons = stoi(tons);

    }

    // if the parameter string is empty, the function will
    // do nothing and just go back to the main method

}

// destructor
Airport::~Airport()
{
    // this is a destructor
}

// Getter methods

/**
 * Returns a string of the airport's name.
 * @return name
*/
string Airport::getName() const
{
    return this->name;
}

/**
 * Returns a string of the airport's state.
 * @return state
*/
string Airport::getState() const
{
    return this->state;
}

/**
 * Returns a string of the airport's city.
 * @return city
*/
string Airport::getCity() const
{
    return this->city;
}

/**
 * Returns a string of the airport's IATA code.
 * @return iata code
*/
string Airport::getIata() const
{
    return this->iata_code;
}

/**
 * Returns an integer representing the number of passengers at an airport.
 * @return number of passengers
*/
int Airport::getNumPassengers() const
{
    return this->numPassengers;
}

/**
 * Returns an integer representing the number of flights at an airport.
 * @return number of flights
*/
int Airport::getNumFlights() const
{
    return this->numFlights;
}

/**
 * Returns an integer representing the weight of the freight (in tons)
 * @return freight weight in tons
*/
int Airport::getFreight() const
{
    return this->freightInTons;
}

// Setter methods

/**
 * Allows a user to set the name of an Airport object.
 * @param n new name
*/
void Airport::setName(string n)
{
    this->name = n;
}

/**
 * Allows a user to set the state of an Airport object.
 * @param s new state
*/
void Airport::setState(string s)
{
    this->state = s;
}

/**
 * Allows a user to set the city of an Airport object.
 * @param c new city
 * 
*/
void Airport::setCity(string c)
{
    this->city = c;
}

/**
 * Allows a user to set the IATA code of an Airport object.
 * @param i new iata code
*/
void Airport::setIata(string i)
{
    this->iata_code = i;
}

/**
 * Allows a user to set the number of passengers of an Airport object.
 * @param p new number of passengers 
*/
void Airport::setNumPassengers(int p)
{
    this->numPassengers = p;
}

/**
 * Allows a user to set the number of flights of an Airport object.
 * @param f new number of flights
*/
void Airport::setNumFlights(int f)
{
    this->numFlights = f;
}

/**
 * Allows a user to set the weight of the freight of an Airport object.
 * @param t new freight weight (in tons)
*/
void Airport::setFreight(int t)
{
    this->freightInTons = t;
}

// Operator overloading

/**
 * Allows a user to check if Airport objects are equal; returns a boolean value.
 * @param rhs the Airport object to compare the calling object to
 * @return true if the Airport objects are equal (regarding all attributes), false if not.
*/
bool Airport::operator==(const Airport &rhs) const
{
    return (this->name == rhs.getName()) &&
           (this->city == rhs.getCity()) &&
           (this->iata_code == rhs.getIata()) &&
           (this->numPassengers == rhs.getNumPassengers()) &&
           (this->numFlights == rhs.getNumFlights()) &&
           (this->freightInTons == rhs.getFreight());
}

/**
 * Allows a user to check if Airport objects are not equal; returns a boolean value.
 * @param rhs the Airport object to compare the calling object to
 * @return true if the Airport objects are not equal (regarding all attributes), false if they are equal.
*/
bool Airport::operator!=(const Airport &rhs) const
{
    return (this->name != rhs.getName()) &&
           (this->city != rhs.getCity()) &&
           (this->iata_code != rhs.getIata()) &&
           (this->numPassengers != rhs.getNumPassengers()) &&
           (this->numFlights != rhs.getNumFlights()) &&
           (this->freightInTons != rhs.getFreight());
}

/**
 * Allows a user to check if the number of passengers in one Airport is less than that of another; returns a boolean value.
 * @param rhs the Airport object to compare the calling object to
 * @return true if the calling object has less passengers than rhs
*/
 bool Airport::operator<(const Airport &rhs) const
{
    return  (this->numPassengers < rhs.getNumPassengers());
}

/**
 * Allows a user to check if the number of passengers in one Airport is greater than that of another; returns a boolean value.
 * @param ths the Airport object to compare the calling object to.
 * @return true if the calling object has more passengers than rhs
*/
 bool Airport::operator>(const Airport &rhs) const
{
    return  (this->numPassengers > rhs.getNumPassengers());
}

/**
 * Allows a user to add more passengers to an Airport object.
 * @param toAdd the number of passengers to add
*/
int Airport::operator+=(int toAdd)
{
   return this->numFlights += toAdd;
}

// friend functions
ostream& operator<<(ostream& out, const Airport& rhs)
{
    out << "Name: " << rhs.name << " " << "State: " << rhs.state << " " <<
    "City: " << rhs.city << " " << "IATA Code: " << rhs.iata_code << " " <<
    "Number of Passengers: " << rhs.numPassengers << " " << "Number of Flights: " <<
    rhs.numFlights << " " << "Freight (in tons): " << rhs.freightInTons;

    return out;

}

istream& operator>>(istream& in, Airport& rhs)
{
    string temp; 

    cout << "Please enter aiport details..." << endl;

    cout << "Name: ";
    in >> temp;
    rhs.setName(temp);

    cout << "State: ";
    in >> temp;
    rhs.setState(temp);

    cout << "City: ";
    in >> temp;
    rhs.setCity(temp);

    cout << "IATA Code: ";
    in >> temp;
    rhs.setIata(temp);

    cout << "Number of Passengers: ";
    in >> temp;
    rhs.setNumPassengers(stoi(temp));

    cout << "Number of Flights: ";
    in >> temp;
    rhs.setNumFlights(stoi(temp));

    cout << "Freight (in tons): ";
    in >> temp;
    rhs.setFreight(stoi(temp));

    return in;
    
}

