#include "hw7truck.h"
#include "hw7common.h"
using namespace std;

Truck::Truck(){} // empty constructor

Truck::Truck(Person & driver, double speed, double width, Place & place, Thing cargo, bool flag){
    this->driver = driver;
    this->speed = speed;
	this->width = width;
	this->position = place;
    this->cargo = cargo;
    this->isCargo = flag;
}

Person Truck::getDriver(){
    return this->driver;
}
Thing Truck::getCargo(){
    return this->cargo;
}
bool Truck::getIsCargo(){
    return this->isCargo;
}

