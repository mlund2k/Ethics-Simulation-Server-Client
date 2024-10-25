#ifndef _AUTOV_H_
#define _AUTOV_H_

#include "hw7common.h"
#include "hw7place.h"
#include "hw7person.h"

using namespace std;

class AutoV{
    protected:
        Person driver;
        double speed;
        double width;
        Place position;
        
    public:
        double getSpeed(); // accessor functions
        double getWidth();
        Place getPosition();
        
        AutoV(); // constructors
        AutoV(Person &, double,double,Place &);
        
        virtual Json::Value dump2JSON(); // JSON functions
        virtual bool JSON2Object(Json::Value);
        Person getDriver();
};
#endif