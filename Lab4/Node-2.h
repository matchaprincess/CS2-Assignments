#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node();
        ~Node();
        Node(int, Node*);
        int getData();
        void setNext(Node *);
        Node* getNext();

    protected:

    private:
        int data;
        Node *next;
};

#endif // NODE_H
