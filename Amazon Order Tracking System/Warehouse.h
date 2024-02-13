#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream> 
#include <string>
#include <iomanip>

#include <vector>
#include "Distributor.h"
#include "Driver.h"


using namespace std;

class Warehouse {		
	public:
    
    // 2. Constructor - initialize any necessary member variables.
    Warehouse();
        
    //Member Functions 
    void addDriver(const string& name, const Location& location);// - add a new Driver with the given parameters.

    void addDistributor(const string& name, const Location& location); // - add a new Distributor with the given parameters.

    /* make a new Order with the given criteria and add it to the Distributor that is closest to the given Location. You may wish to write a
    helper function here - see part 4 below.
    */
    void takeOrder(const string& customerName, int menuItem, const Location& location); 

    /*
    You should loop over all the Drivers and determine what actions they should take
    // and execute those actions. You should output the Driver name and what action they are taking to cout.
    // i. If the Driver isFree() returns true, then they should pickup all the Orders from the Distributor
    // who has the most Orders (you may wish to use a helper function here). The Driver should update
    // their Location to be the same as the Distributor they are picking up Orders from (that is, they
    // "drove" to the Distributor to pick up the Orders).
    // If all Distributors have zero Orders, print out a message like "Driver <name> is taking a lunch
    // break".
    // ii. If the Driver isFree() returns false, then the Driver has more Orders to deliver. Remove the next
    // Order from the Driver and print out that they are delivering the Order. Delete the delivered Order.
    */
    void updateDrivers();

    void printDistributors() const;// - print all the Distributors.

    void printDrivers() const; // print all the Drivers.


    private: 

    //member variables 

    // (a) A data structure that contains Drivers.
    vector<Driver*> driversCollection; 
    
    // (b) A data structure that contains Distributors.
    vector<Distributor*> distributorsCollection; 

    //member functions 
    Distributor* findClosestDriver(const Location& location);

    //Distributor* findClosestDistributor(const Location& location);

    Distributor* findDistributorWithMostOrders(); 
     
	
};
#endif
