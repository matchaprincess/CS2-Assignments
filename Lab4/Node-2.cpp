#include "Node-2.h"

Node::Node()
{
    data = 0;
    next = nullptr;
}

Node::~Node()
{
    //dtor
}

Node::Node(int data, Node* next){
    this->data = data;
    this->next = next;
}



void Node::setNext(Node *next){
    this->next = next;
}

Node* Node::getNext(){
    return next;
}

int Node::getData(){
    return data;
}
