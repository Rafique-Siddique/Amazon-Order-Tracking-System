#include "Warehouse.h"

Warehouse::Warehouse() {};

// - add a new Driver with the given parameters.
void Warehouse::addDriver(const string& name, const Location& location) {
    Driver* temp = new Driver(name, location);
    driversCollection.push_back(temp);
}

 // - add a new Distributor with the given parameters.
 void Warehouse::addDistributor(const string& name, const Location& location) {
    Distributor* temp = new Distributor(name,location);
    distributorsCollection.push_back(temp);
}

/* make a new Order with the given criteria and add it to the Distributor that is closest to the given Location. You may wish to write a
   helper function here - see part 4 below.
*/
void Warehouse::takeOrder(const string& customerName, int menuItem, const Location& location) {
    Distributor* closestDistributor = findClosestDriver(location);

    if(closestDistributor != nullptr) {
        closestDistributor->acceptOrder(customerName, menuItem, location);
    } else {
        cout << "No distributors available to recieve order"  << endl;//ERROR message
    }
}

/*
You should loop over all the Drivers and determine what actions they should take
// and execute those actions. You should output the Driver name and what action they are taking to cout.
// i. If the Driver isFree() returns true, then they should pickup all the Orders from the Distributor
// who has the most Orders (you may wish to use a helper function here). The Driver should update
// their Location to be the same as the Distributor they are picking up Orders from (that is, they
// "drove" to the Distributor to pick up the Orders).
// If all Distributors have zero Orders, print out a message like "Driver <name> is taking a lunch
// break".sx
// ii. If the Driver isFree() returns false, then the Driver has more Orders to deliver. Remove the next
// Order from the Driver and print out that they are delivering the Order. Delete the delivered Order.
*/
void Warehouse::updateDrivers() {
    //iterating over all the drivers in the driversCollection
    for(Driver* driver : driversCollection) {
        //checking if driver has no orders
        if(driver->isFree()) {
            Distributor* distributorWithMostOrders = findDistributorWithMostOrders(); //distributor with most orders
            
            //checking if there exists a distributor with orders available 
            if(distributorWithMostOrders != nullptr) {
                driver->pickupOrders(*distributorWithMostOrders);
                cout <<  "Driver" << driver->getName() << "picked up orders from Distributor" << distributorWithMostOrders->getName()<< endl; 
            } else {
                cout << "Driver" << driver->getName() << " Driver is taking a lunch break." << endl; 
            } 

            Order* deliveredOrder = driver->deliverOrder();
            //check to see if there is orders to be delivered
            if(deliveredOrder != nullptr) {
                cout << "Driver" << driver->getName() << " is delivering an order for " << deliveredOrder->getCustomerName() << "." << endl; 
                delete deliveredOrder;
            } else {
                //handle case where driver is not free
                Order* deliveredOrder = driver->deliverOrder();
                //check to see if there is orders to be delivered
                if(deliveredOrder != nullptr) {
                    cout << "Driver " << driver->getName() << "is delivered an order for "<< deliveredOrder->getCustomerName() << "." << endl; 
                    delete deliveredOrder;
                }
            }
        }
     }

}

// - print all the Distributors.
void Warehouse::printDistributors() const {
    cout << "Print Distributors:" << endl;
    for(Distributor* distributor : distributorsCollection) {
        distributor->print();
    }
}

// print all the Drivers.
void Warehouse::printDrivers() const {
    cout << "Print Drivers:" << endl;
    for(const Driver* driver : driversCollection) {
        driver->print();
    }
}

//helper functions
Distributor* Warehouse::findClosestDriver(const Location& location) {
    //check to see if distributor collection is empty 
    if(distributorsCollection.empty()) {
        cout << "No available drivers" << endl; 
        return nullptr; 
    }

    Distributor* closetDriver = distributorsCollection[0];
    int minDistance = distributorsCollection[0]->getLocation().getDistance(location);

    //iterate over distributors in the distributorsCollection
    for(size_t i=1; i < distributorsCollection.size(); i++)  {
        int distance = distributorsCollection[i]->getLocation().getDistance(location);
        if(distance < minDistance) {
            minDistance = distance; 
            closetDriver = distributorsCollection[i];
        }
    }
    return closetDriver;
}

Distributor* Warehouse::findDistributorWithMostOrders(){
    //check to see if distributor collection is empty 
    if(distributorsCollection.empty()) {
        cout << "No available distributors " << endl;
        return nullptr;
    }

    Distributor* distributorWithMostOrders = distributorsCollection[0];

    int maxOrders = distributorsCollection[0]->getNumOrders();

    //iterate over distributors in the distributorsCollection
    for(size_t i=1; i < distributorsCollection.size(); i++) {
    int numOrders = distributorsCollection[i]->getNumOrders();

    //check to see if current distributor has more orders than max orders
    if(numOrders > maxOrders) {
        maxOrders = numOrders;
        distributorWithMostOrders = distributorsCollection[i];
        }
    }
    //return distributor with most orders
    return distributorWithMostOrders;
}
