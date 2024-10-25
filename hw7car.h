#ifndef _CAR_H_
#define _CAR_H_
#include "hw7common.h"
#include "hw7mcycle.h"

using namespace std;

class Car : public AutoV{
    private:
        Person driver;
        Place position;
        Person passenger;
    public:
        Person getDriver(); // accessor functions
        Person getPassenger(); // contains bool flag
        
        Car(); // constructors
        Car(Person &, double, double, Place&);
};

#endif