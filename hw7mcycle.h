#ifndef _MCYCLE_H_
#define _MCYCLE_H_
#include "hw7common.h"
#include "hw7autov.h"
#include "hw7person.h"
#include "hw7place.h"
using namespace std;

class MCycle : public AutoV{
    private:
        Person driver;
        Place position;
        bool isAlert = false; // if set to true, motorcycle will be alerted
        bool isCollide = false; // if set to true, collision imminent
    public:
        MCycle(); // constructors
        MCycle(Person &, double,double,Place&);
        
        virtual Json::Value dump2JSON(); // JSON functions
        virtual bool JSON2Object(Json::Value);
        
        Person getRider(); // accessor functions
        Person getDriver();
        bool getIsAlert();
        bool getIsCollide();
        
        void setAlert(bool); // mutator functions for other vehicles to alert motorcycles
        void setCollide(bool);
};

#endif