
#include "Controller.h"
#include <sstream>
#include <limits>

#define ARR 5

const string names[5] = {"Abe", "Bae", "Cedric", "Deb", "Elise"};
const int menuItems[5] = {1, 2, 3, 3, 2};
const Location locs[5];



void Controller::launch()
{
    // add some drivers and Distributors
    initWarehouse();

    // write the menu and get user input
    int choice = -1;

    // This is the code being run in View
    // cout << "What would you like to do?"<< endl;
    // cout << "  (0) Exit." << endl;
    // cout << "  (1) Add driver." << endl;
    // cout << "  (2) Add distributor." << endl;
    // cout << "  (3) Generate orders." << endl;
    // cout << "  (4) Update drivers." << endl;
    // cout << "  (5) Print all drivers." << endl;
    // cout << "  (6) Print all distributors."<<endl;
    // cout << endl;

    // cout << "  Tests:"<<endl<<endl;
    // cout << "  (7) takeOrder test."<<endl;
    // cout << "  (8) Driver pickup test."<<endl;
    // cout << "  (9) Driver deliver test."<<endl;
    // cout << "  (10) Student tests."<<endl;


    while (choice != 0)
    {
        int temp = 0;
        view.displayMenu(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice)
        {
        case 1:
            addDriver();                    break;
        case 2:
            addDistributor();               break;
        case 3:
            generateNewOrders();            break;
        case 4:
            updateDrivers();                break;
        case 5:
            warehouse.printDrivers();       break;
        case 6:
            warehouse.printDistributors();  break;
        case 7:
            takeOrderTest();                break;
        case 8:
            driverPickupTest();             break;
        case 9:
            driverDeliverTest();            break;
        case 10:
            studentTests();                 break;
        }
    }

    cout << "Bye!" << endl;
}



void Controller::addDriver()
{
    string name;
    Location loc;

    view.getEntityInfo(name, loc);
    warehouse.addDriver(name, loc);
}

void Controller::addDistributor()
{
    string name;
    Location loc;

    view.getEntityInfo(name, loc);
    warehouse.addDistributor(name, loc);
}

void Controller::updateDrivers()
{
    cout << "Updating drivers..." << endl;
    warehouse.updateDrivers();
}





void Controller::initWarehouse()
{

    warehouse.addDriver("Elsa", Location(3, 4));
    warehouse.addDriver("Densel", Location(1, 1));
    warehouse.addDriver("Carter", Location(5, 4));
    

    warehouse.addDistributor("Sally", Location(5, 5));
    warehouse.addDistributor("Isabelle", Location(5, 1));
    warehouse.addDistributor("Philip", Location(1, 7));

    // generate 6 random orders to start with
    for (int i = 0; i < 6; ++i)
    {
        warehouse.takeOrder(customers[ran(0, 10)], ran(0, 10), Location(ran(0, 10), ran(0, 10)));
    }

}

void Controller::generateNewOrders()
{
    int numOrders = 0;
    view.getNumOrders(numOrders);
    for (int i = 0; i < numOrders; ++i)
    {
        warehouse.takeOrder(customers[ran(0, 10)], ran(0, 10), Location(ran(0, 10), ran(0, 10)));
    }
}

void Controller::initCapture()
{
    oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream temp;
    strCout.swap(temp);
    std::cout.rdbuf(strCout.rdbuf());
}

void Controller::endCapture()
{
    std::cout.rdbuf(oldCoutStreamBuf);
    output = strCout.str();
    std::cout << output;
}

void Controller::pressEnterToContinue()
{
    cout << "Press enter to continue..." << endl;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char c = cin.get();
    while (c != '\n')
    {
        c = cin.get();
    }
}

// generate and return a single random number in the range range_from to range_to - 1
int Controller::ran(int range_from, int range_to)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range_from, range_to - 1);
    return distr(generator);
}

// s is the set to store count random numbers from 0 to range - 1
void Controller::ran(vector<int> &list, int count, int range)
{
    unordered_set<int> s;
    const int range_from = 0;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range_from, range - 1);

    while (s.size() < count)
    {
        s.insert(distr(generator));
    }
    unordered_set<int>::iterator it;
    for (it = s.begin(); it != s.end(); ++it)
    {
        list.push_back(*it);
    }
}

/* Add your tests here */
void Controller::studentTests()
{
    //test 1: adding driver
    warehouse.addDriver("TestDriver1", Location(1,1));
    warehouse.printDrivers();
    cout << "Expected output: TestDriver1 at (1,1)" << endl;
    pressEnterToContinue();

    //test 2: adding distributor
    warehouse.addDistributor("TestDistributor1", Location(5,5));
    warehouse.printDistributors();
    cout << "Expected output: TestDistributor1 at (5,5)" << endl;
    pressEnterToContinue();

    //test 3: taking an order
    warehouse.takeOrder("TestCustomer1", 3, Location(2,3));
    warehouse.printDistributors();
    cout << "Expected output: TestDistributor1 has 1 order" << endl;
    pressEnterToContinue();

    //test 4: updating drivers
    warehouse.addDriver("TestDriver2", Location(4,4));
    warehouse.addDriver("TestDriver3", Location(7,7));
    updateDrivers();
    warehouse.printDrivers();
    cout << "Expected output: TestDriver1 and TestDriver2 have 1 order each" << endl;
    pressEnterToContinue();



    cout<<endl<<messages[ran(0,10)]<<endl;
}

void Controller::takeOrderTest(){
    Warehouse *w = new Warehouse();
    w->addDistributor("A", Location(1,1));
    w->addDistributor("B", Location(9,9));
    w->takeOrder("John", 6, Location(8,8));
    w->takeOrder("Bob", 8, Location(10,10));
    w->printDistributors();

    cout<<endl<<"Should be 2 orders at B"<<endl;

    pressEnterToContinue();  

    w->takeOrder("Amy", 6, Location(1,2));
    w->takeOrder("Sue", 8, Location(3,3));

    w->printDistributors();

    cout<<endl<<"Should be 2 orders at B and 2 orders at A."<<endl;
    cout << "1/2 marks for a mistake, but there are still 4 orders total."<<endl;
    cout << "0/2 marks for anything other than 4 orders total."<<endl;

    pressEnterToContinue();

    delete w;
   
}

void Controller::driverPickupTest(){
    Warehouse *w = new Warehouse();
    w->addDistributor("A", Location(1,1));
    w->takeOrder("Amy", 6, Location(1,2));
    w->addDistributor("B", Location(9,9));
    w->takeOrder("John", 6, Location(8,8));
    w->takeOrder("Bob", 8, Location(10,10));
    w->addDistributor("C", Location(5,5));
    w->takeOrder("Sue", 8, Location(3,5));
    w->takeOrder("Joe", 8, Location(4,4));
    w->takeOrder("Jane", 8, Location(6,6));
   
    

    w->printDistributors();

    cout<<endl<<"Should be 1,2, and 3 orders at A, B, and C respectively"<<endl;
    cout<< "(if the numbers are different, please take note of which Distributor"<<endl;
    cout<< "has the most orders, second most, etc)."<<endl;

    pressEnterToContinue();

    w->addDriver("Driver 1", Location(1,1));
    w->addDriver("Driver 2", Location(9,9));

    w->updateDrivers();

    w->printDistributors();
    w->printDrivers();


    cout<<"3/3 marks if the Drivers picked up all orders from 2 Distributors with the most orders."<<endl;
    cout<<"2/3 marks if both Drivers picked up all orders from any 2 Distributors"<<endl;   
    cout<<"1/3 marks for some Driver picked up something."<<endl;

    pressEnterToContinue();

    delete w;
}

void Controller::driverDeliverTest(){
    Warehouse *w = new Warehouse();
    w->addDistributor("A", Location(1,1));
    w->takeOrder("Amy", 6, Location(1,2));
    w->takeOrder("Sue", 8, Location(3,5));
    w->takeOrder("Joe", 8, Location(4,4));

    w->addDistributor("B", Location(9,9));
    w->takeOrder("John", 6, Location(8,8));
    w->takeOrder("Bob", 8, Location(10,10));
    
    w->addDriver("Driver 1", Location(1,1));
    w->addDriver("Driver 2", Location(9,9));

    cout<<"Updating Drivers"<<endl;
    w->updateDrivers();

    w->printDistributors();
    w->printDrivers();

    cout<<endl<<"Drivers should have 3 and 2 orders, attempting to deliver"<<endl;

    pressEnterToContinue();
    w->updateDrivers();
    w->printDrivers();

    cout<<endl<<"Drivers should have 2 and 1 orders, should have Locations (1,2) and (8,8)"<<endl;
    pressEnterToContinue();
    w->updateDrivers();
    w->printDrivers();

    cout<<endl<<"Drivers should have 1 and 0 orders, should have Locations (3,5) and (10,10)"<<endl;
    w->takeOrder("John", 6, Location(8,8));
    w->takeOrder("Bob", 8, Location(10,10));
    pressEnterToContinue();
    w->updateDrivers();
    w->printDrivers();

    cout<<endl<<"Drivers should have 0 and 2 orders, should have Locations (4,4) and (9,9)"<<endl;



    cout<<"3/3 marks if Drivers delivered and had correct locations."<<endl;
    cout<<"2/3 marks if Drivers delivered but did not update locations"<<endl;
    cout<<"1/3 marks if Drivers delivered but did not pick up orders a second time, or some other error"<<endl;

    pressEnterToContinue();

    delete w;
}

const string Controller::messages[10] = {
    "Sure I've got some toast, right here. Wait, what? Oh, *tests*. That makes a lot more sense. Then no, there are no tests.",
    "There was a test, right there, but you scared it away.",
    "Did I mention you could write some tests in this function?",
    "These tests won't write themselves, you know. Unless you have CoPilot. Then they will. But they might not be very good.",
    "But who will test the tests?",
    "\n🎉🎉🎉  Test passed!  🎉🎉🎉\n\nJust kidding, there are no tests.",
    "Testing ... that part ... with the Driver ... I got nothing.",
    "Just get ChatGPT to write some tests for you...",
    "Have you seen any tests around here? I am looking for some tests.",
    "What is a test, really? Like, aren't we all just testing each other?"};