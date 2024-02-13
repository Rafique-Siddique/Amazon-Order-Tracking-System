#include "Distributor.h"

int Distributor::nextId =1; 

//constructor
Distributor::Distributor(const string& name, const Location& location) :Entity(code, nextId, name, EntityLocation){
    nextId++;
    }
 
// function. This should create a new Order using the provided arguments and add it to the Queue.
Order* Distributor::acceptOrder(const string& customerName, int product, const Location& location) {
    Order* newOrder = new Order(customerName, product, location); //create a new order with the provided argunments 
    orders.addLast(newOrder); // add the new order to the distributor queue
    return newOrder;

}

/* You should transfer all Orders in the this Distributors
Queue to o. This should work in conjunction with the Driver::pickupOrders(Distributor& dist)
function.*/
void Distributor::driverPickup(Queue& o) {
     o.addAll(orders); 
}


//Override the print function. This should behave similar to Entity::print but should specify that this is a Distributor.
void Distributor::print() const {
    cout << "Distributor ID: " << id << endl; 
    cout << "Distributor Name: " << name << endl;
    cout << "Distributor Location: " << endl;
    getLocation().print();
    cout << "Number of Orders in Distributors Queue: " << getNumOrders() << endl;
    Entity::print();
}
