#include "Queue.h"

Queue::Queue():head(nullptr) {}


Queue::~Queue(){

   //declaring variables 
   Node* curr = head;
   Node* prev;


   //check to see if the curr node is not equal to a null pointer 
   while(curr!= nullptr){
      prev = curr;
      curr = curr->next;
      delete prev;
   }
  
}

bool Queue::isEmpty() const {
    return head == nullptr;//temp value 
}

//getter for the orderNum variable 
int Queue::getSize() const {
    return orderNum;
}

const Order* Queue::peekFirst() const {

    //checking to see if the head is not equl to then null pointer 
    if(head != nullptr) {
        return head->data;
    } 

    //otherwise return null pointer 
    return nullptr;
}


Order* Queue::popFirst() {

    // //checking to see if the head is not equl to then null pointer 
    if(head != nullptr) {
        // declaring variable 
        Node* temp = head;
        head = head->next;
        Order* data = temp->data;

    //     //deleting temp variable 
        delete temp;

    //     //decrementing the order number since we are popping 
        orderNum--;

    //if queue is empty set tail to the null pointer 
        if(isEmpty()) {
            tail = nullptr;
        }
        //returnn the data 
        return data;

    }
    //return the null pointer 
    return nullptr;
}


void Queue::addLast(Order* order) {
    //creating a new node variable 
    Node* newNode = new Node(order);

    //checkin to see if the function is empty 
    if(isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    //incrementing the order counter 
    orderNum++;
}

void Queue::addAll(Queue& queue) {

    while(!queue.isEmpty()) {
        addLast(queue.popFirst());
    }

}





