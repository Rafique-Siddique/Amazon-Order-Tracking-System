#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Location.h"
#include "Queue.h"


using namespace std;

class Entity {
		
	public:

		//constructor
		Entity(char entityCode, int entityId, const string& entityName, const Location& loc);
		// ~Entity();
    
		//getters
		const string getName() const;
		const string getId() const;
		const Location getLocation() const;


        //setters
		void setEntityLocation(const Location& location); 
		
		//other
		//Make a getNumOrders() function that returns the number of Orders this Entity has in its Queue.
		int getNumOrders() const;

		//Make a equals function that accepts a string isd as an argument and returns true if this Entity::id is equal	to it and false otherwise.
		bool equals(const string& id) const; // change 

		//return number of orders 
		Queue& getOrders();

		//Make a print function that prints out all the information including Location and number of Orders (you do not need to print out the Orders themselves
		void print() const;//prints metadata not including content 
	
	protected:
	
		//functions
		
		
		//variables
		string id; //The unique id of this Entity.
		string name; //The name of the Driver or Distributor.
		Location EntityLocation;// The location of this Entity.
		Queue orders; //The orders at this Distributor awaiting pickup by a Driver, or the orders currently being delivered by a Driver.


};
#endif
