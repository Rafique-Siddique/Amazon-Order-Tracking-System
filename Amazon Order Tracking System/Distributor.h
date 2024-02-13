#ifndef DISTRIBUTOR_H
#define DISTRIBUTOR_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Driver.h"

using namespace std;


class Distributor : public Entity {		

	public:

        //variables
		static const char code = 'B';
        static int nextId; //roduce the next id number to be passed into the Entity constructor.

		//constructor
		Distributor(const string& name, const Location& location);
		
		//other

        // function. This should create a new Order using the provided arguments and add it to the Queue.
        Order* acceptOrder(const string& customerName, int product, const Location& location);

        /* You should transfer all Orders in the this Distributors
        Queue to o. This should work in conjunction with the Driver::pickupOrders(Distributor& dist)
        function.*/
        void driverPickup(Queue& o); 

        //Override the print function. This should behave similar to Entity::print but should specify that this is a Distributor.
		void print() const;//prints metadata not including content 
	
};
#endif
