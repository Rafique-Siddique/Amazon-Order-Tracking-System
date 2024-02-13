#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Entity.h"

//forward declaratoin for distributor class
class Distributor;



using namespace std;

//inheriting from the Entity class 
class Driver : public Entity {		
	public:

        //static variables
		static const char code = 'A';
        static int nextId; //roduce the next id number to be passed into the Entity constructor.

		//constructor
		Driver(const string& name, const Location& location);

        //default constructor 
        //Driver();  

        /*make a getDistance function that takes a Location as an argument and returns
        the distance from this->Location to the Location argument.*/
        int getDistance(const Location& location);

		
		//other
        /* Return true if the Driver currently has no Orders in their Queue, and false
        if they have one or more Orders in their Queue (i.e., they are still delivering).*/
        bool isFree();

        Order* deliverOrder(); //This should return the next Order in the Queue or nullptr if the Queue is empty.

       /*This should set the Driver’s Location to be the
        same as the Distributor’s Location, and every Order in the Distributor should be added to the
        Driver. After this operation, dist.getNumOrders() should return 0. Note: this function and the
        Distributor::driverPickup(Queue& o) functions (see below) work together in a Visitor pattern.
         this case the Visitor pattern is used as a way of exposing private details to each other without using
        public getters (which anyone can access).
        */

        void pickupOrders(Distributor& dist);

        //Override the print function. This should behave similar to Entity::print but should specify that this is a Driver.
		void print() const;//prints metadata not including content 
	
};
#endif
