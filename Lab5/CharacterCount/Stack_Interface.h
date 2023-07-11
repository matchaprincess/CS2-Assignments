#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

template<typename T>
class Stack_Interface
{
    public:
        virtual bool isEmpty() = 0;
        virtual bool push(const T&) = 0;
        virtual bool pop()  = 0;
        virtual T peek() = 0;


};

#endif // STACK_INTERFACE_H
