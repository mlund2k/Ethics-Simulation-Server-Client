#include "hw7car.h"
#include "hw7common.h"
using namespace std;

Car::Car(){} // empty constructor

Car::Car(Person & driver, double speed, double width, Place &place){
    this->driver= driver;
    this->speed = speed;
    this->width = width;
    this->position = place;
}

Person Car::getDriver(){
    return this->driver;
}
