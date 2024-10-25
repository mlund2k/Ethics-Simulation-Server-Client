#ifndef _PLACE_H_
#define _PLACE_H_

#include "hw7common.h"
using namespace std;

class Place{
    private:
        double longitude;
        double latitude;
    public:
        double getLongitude(); // accessor functions
        double getLatitude();
        
        Place(); // constructors
        Place(double,double);
        
        virtual Json::Value dump2JSON(); // JSON functions
        virtual bool JSON2Object(Json::Value);
};

#endif