#ifndef QUEUE_H
#define QUEUE_H
#include "Order.h"

using namespace std;

class Queue {

    public:
        
        //empty constructor
        Queue();

        ~Queue();


        //getters
        
        //other

        // - return true if the Queue is empty.
        bool isEmpty() const; 

        int getSize() const; // - return the number of Orders in the Queue.

        /*const; //-return the Order* data from the first location if it exists, or return
        nullptr otherwise. DO NOT delete the Node - this function returns the data without removing it from
        the Queue.*/
        const Order* peekFirst() const;
        
        /*- return the Order* data from the first location if it exists, return nullptr otherwise.
        Delete the Node if it exists making sure to update the head and tail pointers if necessary.*/
        Order* popFirst();
        
        /*//- Add order to the back of the Queue. For full marks this should make use of
        the tail pointer in order to add the order without traversing the entire Queue.*/
        void addLast(Order* order);

        /*- all Orders from queue should removed from queue and added to the current
        (this) Queue. There is an easy way to do this by adding elements one at a time (linear time) - bonus
        marks if you can do this by adding all elements at once (constant time).
        For further clarification, consider this example. Initially when addAll(Queue& queue) is called this->getSize()
        returns 5 and queue.getSize() returns 8. Just before returning from addAll, this->getSize() should
        return 13 and queue.getSize() should return 0*/
        void addAll(Queue& queue);

       // void print() const; //print metadata 

    private:
        //nested class 
         class Node{
            public:
                Order* data;
                Node* next;

                Node(Order* order) : data(order), next(nullptr) {}
        };


        //member variables 
         Node* head;
         Node* tail; 
         int orderNum; //keep track of number of orders in the Queue
  
};

#endif
