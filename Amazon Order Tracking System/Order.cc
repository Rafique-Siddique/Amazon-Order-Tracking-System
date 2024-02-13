#include "Order.h"

//constructor
Order::Order(const string& CustomerName, int ProductId, Location location) : CustomerName(CustomerName), ProductId(ProductId), location(location) {}

//declaring the PRODUCTs array 
const string Order::PRODUCTS[NUM_PRODUCTS] = {
    "Bike", "Book", "Computer", "TV", "Skateboard", "Rollerblades",
    "Unicycle", "Toothbrush", "Toothpaste", "Floss"
};
	
//getters
Location Order::getLocation() const {return location;}
string Order::getCustomerName() const {return CustomerName;}//getting the customer name 
int Order::getProductId() const {return ProductId;}//getting the product Id


//other
void Order::print() const {
    if((ProductId >= 0) && (ProductId < NUM_PRODUCTS)) {
        cout << "Customer: " << CustomerName << ", Product: " << PRODUCTS[ProductId] << endl; 
        cout << "Location of Delivery: ";
        location.print();
        cout << endl;
    } else {
        cout << "Invalid id entered" << endl;
    }    
}