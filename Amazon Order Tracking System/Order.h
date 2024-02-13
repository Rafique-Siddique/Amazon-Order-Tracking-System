#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Location.h"

#include "defs.h"

using namespace std;

class Order {
		
	public:

		//constructor
		Order(const string& CustomerName, int ProductId, Location location);
        
        static const string PRODUCTS []; //list of products 

		//getters
		Location getLocation() const; //getting for location
        string getCustomerName() const; //getting the customer name 
        int getProductId() const; //getting the product Id
		
		//other
		void print() const;//prints metadata not including content 
	
	private:
		//functions
		
		//variables
        string CustomerName; //customer name
        int ProductId; //number of the product ordered.
        Location location; //The location to be delivered

};
#endif
