
#ifndef PACKET_H
#define PACKET_H

#include <string>

using namespace std; 

class Packet
{
private:
    string id;
    int size;
    int priority;

public: 
    Packet();
    Packet(string data);
    ~Packet();
    string getID() const;
    int getSize() const;
    int getPriority() const;
    void setID(string newID);
    void setSize(int newSize);
    void setPriority(int newPriority);

    // overloaded operators
    bool operator<(const Packet &rhs);
    bool operator>(const Packet &rhs);
    bool operator>=(const Packet &rhs);
    bool operator<=(const Packet &rhs);
    bool operator!=(const Packet &rhs);
    bool operator==(const Packet &rhs);

    // friend functions
    friend ostream& operator<<(ostream& out, const Packet& rhs);


};

#endif