
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include <random>
#include <unordered_set>
#include <sstream>
#include "Warehouse.h"
#include "View.h"






using namespace std;

class Controller {
		
	public:
		
		void launch();

	
	private:
		// Initializing functions
		void initWarehouse();
		void generateNewOrders();

		// User interface functions
		void addDriver();
		void addDistributor();
		void updateDrivers();

		// helper functions
		void pressEnterToContinue();
		void initCapture();
		void endCapture();	
		/* generate a set (no duplicates) of "count" random integers
		 rom 0 to "range", return the integers in "list" */
		void ran(vector<int>& list, int count, int range);
		// generate a random integer in the given range and return it
		int ran(int range_from, int range_to);

		// test functions
		void studentTests();
		// int edgeTest();
		// int orderTest();
		// int pickupOrderTest();
		void takeOrderTest();
		void driverPickupTest();
		void driverDeliverTest();
		
    
		// data members

		// data members for test purposes
		const string customers[10] = {"Abe","Bae","Cedric","Deb","Elise", "Farah", "Gabe", "Hannah", "Ivan", "Jen"};
		streambuf* oldCoutStreamBuf;
    	ostringstream strCout;
		string output;
		
		// data members for the warehouse and view
		Warehouse warehouse;
		View view;

		// goofy messages
		static const string messages[10];

};
#endif