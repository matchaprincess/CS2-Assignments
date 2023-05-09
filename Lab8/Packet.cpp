/** @file Packet.cpp * /
* @author Valerie Williams
* @date 4/23/2023
* @version 1
* Represents a packet of data with an ID, its size, and its priority level.
*/

#include <string>
#include "Packet.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * Constructs a packet object with no parameters.
*/
Packet::Packet()
{

    id = "NA";
    size = 0;
    priority = 0;

}

/**
 * Constructs a packet object with a line of data from a csv file.
 * @param data a line from a csv file containing a packet id, size, and priority level
*/
Packet::Packet(string data)
{

    // create placeholder variables
    string i = " ";
    string s = " ";
    string p = " ";

    // create the stringstream object
    stringstream ss(data);

    // if the parameter isn't empty, parse the data out
    if (!data.empty())
    {

        // parse out the string
        getline(ss, i, ',');
        getline(ss, s, ',');
        getline(ss, p, '\r');

        // set the attributes to the data that was parsed out
        this->id = i;
        this->size = stoi(s);
        this->priority = stoi(p);

    }

    // if the string parameter is empty, this won't do anything

}

/**
 * Destroys a packet object.
*/
Packet::~Packet()
{

}

/**
 * Returns the ID of a packet.
 * @return the calling packet's id
*/
string Packet::getID() const
{
    return id;
}

/**
 * Returns the size of a packet.
 * @return the calling packet's size
*/
int Packet::getSize() const
{
    return size;
}

/**
 * Returns the priority level of a packet.
 * @return the calling packet's priority level
*/
int Packet::getPriority() const
{
    return priority;
}

/**
 * Allows a user to change a packet's ID.
 * @param newID the new ID for the packet
*/
void Packet::setID(string newID)
{
    id = newID;
}

/**
 * Allows a user to change a packet's file size.
 * @param newSize the new file size for the packet
*/
void Packet::setSize(int newSize)
{
    size = newSize;
}

/**
 * Allows a user to change a packet's priority level.
 * @param newPriority the new priority level for the packet
*/
void Packet::setPriority(int newPriority)
{
    priority = newPriority;
}

bool Packet::operator<(const Packet &rhs)
{
    return (this->priority < rhs.getPriority());
}

bool Packet::operator>(const Packet &rhs)
{
    return (this->priority > rhs.getPriority());

}

bool Packet::operator<=(const Packet &rhs)
{
    return (this->priority <= rhs.getPriority());
   
}

bool Packet::operator>=(const Packet &rhs)
{
    return (this->priority >= rhs.getPriority());

}

bool Packet::operator==(const Packet &rhs)
{
    return (this->priority == rhs.getPriority());
}

bool Packet::operator!=(const Packet &rhs)
{
    return (this->priority != rhs.getPriority());
}

ostream& operator<<(ostream& out, const Packet& rhs)
{

    out << "ID: " << rhs.getID() << " " << "Size: " << rhs.getSize() << " " << "Priority: " << rhs.getPriority();
    return out;

}
