#ifndef _PRIORITY_QUEUE_INTERFACE
#define _PRIORITY_QUEUE_INTERFACE

template<typename T>
class PriorityQueueInterface
{
public:
   /** determines if this heap is empty.
    @return True if the heap is empty, false if not.
    */
   virtual bool isEmpty() const = 0;




   /** Returns the number of nodes in this heap.

    @return The number of nodes in this heap.
    */
   virtual int getNumberOfNodes() const = 0;





   /** Returns the data that is in the root (top) of this heap, but does not dequeue it.
    For a maxheap, the data at the top is the largest value in the heap;
    for a minheap, the data at the top is the smallest value in the heap.

    @return The data in the root of the heap.
    */
   virtual T peek() const = 0;




   /** Adds a new node to this heap.
    @param newData The data for the new node.
    @return True if the addition is successful, false if not.
    */
   virtual bool add(const T& newData) = 0;




   /** Removes the root node from this heap.
    @return True if the removal is successful, false if not.
    */
   virtual bool remove() = 0;

   /** Removes all nodes from this heap.
   */
   virtual void clear() = 0;
}; // end PriorityQueueInterface
#endif
