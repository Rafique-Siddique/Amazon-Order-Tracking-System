
#include "View.h"
#include <sstream>
#include "Driver.h"
#include "Warehouse.h"

using namespace std;


void View::displayMenu(int& choice){
    int numOptions = 10;

    cout << endl;
    cout << "What would you like to do?"<< endl;
    cout << "  (0) Exit." << endl;
    cout << "  (1) Add driver." << endl;
    cout << "  (2) Add distributor." << endl;
    cout << "  (3) Generate orders." << endl;
    cout << "  (4) Update drivers." << endl;
    cout << "  (5) Print all drivers." << endl;
    cout << "  (6) Print all distributors."<<endl;
    cout << endl;

    cout << "  Tests:"<<endl<<endl;
    cout << "  (7) Take order test."<<endl;
    cout << "  (8) Driver pickup test."<<endl;
    cout << "  (9) Driver deliver test."<<endl;
    cout << "  (10) Student tests."<<endl;


    cout << "Enter your selection: ";
    cin >> choice;
    if (choice == 0)
        return;

    while (choice < 0 || choice > numOptions) {
        cout << "Enter your selection: ";
        cin >> choice;
    }
}

void View::getNumOrders(int& numOrders){
    cout<<"Enter number of orders to generate: ";
    cin >> numOrders;
}

void View::getEntityInfo(string& name,  Location& loc){
    cout<<"Enter entity name: ";
    cin >> name;
    cout << endl;
    cout<<endl<<"Enter location (two integers: x y): ";
    cin >> loc.x >> loc.y;
}



