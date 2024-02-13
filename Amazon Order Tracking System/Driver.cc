#include "Driver.h"
#include "Distributor.h"

int Driver::nextId = 1;

//increment nextId for each new driver 
Driver::Driver(const string& name, const Location& location) :Entity(code, nextId, name, location){
    nextId++;//incrementing nextId
}

/* Return true if the Driver currently has no Orders in their Queue, and false
if they have one or more Orders in their Queue (i.e., they are still delivering).*/
bool Driver::isFree() {
    return orders.isEmpty(); //check if drivers queue is empty 
}

//This should return the next Order in the Queue or nullptr if the Queue is empty.
Order* Driver::deliverOrder() {
    if(!orders.isEmpty()) {
        Order* nextOrder = orders.popFirst();
        setEntityLocation(nextOrder->getLocation()); //updates drivers location
        return nextOrder;
    }
    return nullptr; // return the next order in the queue or nullptr if it is empty 
}

/*make a getDistance function that takes a Location as an argument and returns
        the distance from this->Location to the Location argument.*/
int Driver::getDistance(const Location& location) {
    return getLocation().getDistance(location);
}

/*This should set the Driver’s Location to be the
same as the Distributor’s Location, and every Order in the Distributor should be added to the
Driver. After this operation, dist.getNumOrders() should return 0. Note: this function and the
Distributor::driverPickup(Queue& o) functions (see below) work together in a Visitor pattern.
    this case the Visitor pattern is used as a way of exposing private details to each other without using
public getters (which anyone can access).
*/

void Driver::pickupOrders(Distributor& dist) {
    
    setEntityLocation(dist.getLocation()); // set the drivers location to the Distributors location 
    orders.addAll(dist.getOrders()); // add all the distributors to the Drivers queue
}

//Override the print function. This should behave similar to Entity::print but should specify that this is a Driver.
void Driver::print() const {
    cout << "Driver ID: " << getId() << endl; 
    cout << "Driver Name: " << getName() << endl;
    cout << "Driver Location: " << endl;
    getLocation().print();
    cout << "Number of Orders in Queue: " << getNumOrders() << endl;
    Entity::print(); //overiding print function
}
