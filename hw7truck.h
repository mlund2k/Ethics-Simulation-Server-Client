#ifndef _TRUCK_H_
#define _TRUCK_H_
#include "hw7common.h"
#include "hw7autov.h"
#include "hw7person.h"
#include "hw7thing.h"
#include "hw7place.h"
using namespace std;

class Truck : public AutoV{
    private:
        Person driver;
        Place position;
        Thing cargo;
        bool isCargo; // returns true if cargo is intact
    public:
        Person getDriver(); // accessor functions
        Thing getCargo();
        bool getIsCargo();
        
        Truck(); // constructors
        Truck(Person&, double,double,Place &,Thing,bool);
};

#endif