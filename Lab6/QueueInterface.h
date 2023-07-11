#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

template <typename T>
class QueueInterface {
public:
    virtual bool isEmpty() = 0;
    virtual bool dequeue() = 0;
    virtual bool enqueue(T ) = 0;
    virtual T peek() = 0;

};

#endif // QUEUEINTERFACE_H
