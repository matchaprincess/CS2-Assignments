// Airport.h header file

#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include "BinarySearchTree.h"
#include "Node.h"

using namespace std;

class Airport
{

    public:
    Airport();
    Airport(string a);
    ~Airport();
    string getName() const;
    string getState() const;
    string getCity() const;
    string getIata() const;
    int getNumPassengers() const;
    int getNumFlights() const;
    int getFreight() const;
    void setName(string n);
    void setState(string s);
    void setCity(string c);
    void setIata(string i);
    void setNumPassengers(int p);
    void setNumFlights(int f);
    void setFreight(int t);
    bool operator==(const Airport &rhs) const;
    bool operator!=(const Airport &rhs) const;
    bool operator<(const Airport &rhs) const;
    bool operator>(const Airport &rhs) const;
    int operator+=(int toAdd);
    friend ostream& operator<<(ostream& os, const Airport &rhs);
    friend istream& operator>>(istream& is, const Airport &rhs);

    private:
    string name;
    string state;
    string city;
    string iata_code;
    int numPassengers;
    int numFlights;
    int freightInTons;

};

#endif