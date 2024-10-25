#ifndef _THING_H_
#define _THING_H_
#include "hw7common.h"
using namespace std;

class Thing{
    private:
        string thing;
    public:
        string getThing(); // accessor function
        
        Thing(); // constructors
        Thing(string);
        
        virtual Json::Value dump2JSON(); // JSON function
};

#endif