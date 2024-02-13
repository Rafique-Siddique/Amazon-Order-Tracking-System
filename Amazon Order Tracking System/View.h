
#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <sstream>
#include "defs.h"
#include "Location.h"

using namespace std;

class View {
		
	public:	
		void displayMenu(int& choice);
		void getNumOrders(int& numOrders);
		void getEntityInfo(string& name, Location& loc);
};
#endif