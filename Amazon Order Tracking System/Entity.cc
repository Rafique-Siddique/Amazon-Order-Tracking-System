#include "Entity.h"

Entity::Entity(char entityCode, int entityId, const string& entityName, const Location& loc) {
    id = entityCode + to_string(entityId);
    name = entityName;
    EntityLocation = loc;
}

// ~Entity();

//getters
const string Entity::getName() const {return name;}

const string Entity::getId() const {return id;}

const Location Entity::getLocation() const {return EntityLocation;}

//setters
void Entity::setEntityLocation(const Location& location) {
    EntityLocation = location;
} 

//other
//Make a getNumOrders() function that returns the number of Orders this Entity has in its Queue.
int Entity::getNumOrders() const { 
    return orders.getSize();
}

//Make a equals function that accepts a string id as an argument and returns true if this Entity::id is equal to it and false otherwise.
bool Entity::equals(const string& entityId) const{
    return id == entityId; //temp value
}

Queue& Entity::getOrders() {return orders;}

//Make a print function that prints out all the information including Location and number of Orders (you do not need to print out the Orders themselves
void Entity::print() const {
    
    cout << "Entity ID: " << id << endl; 
    cout << "Name: " << name << endl;
    EntityLocation.print();
    cout << "Number of Orders: " << getNumOrders() << endl;
    
}




