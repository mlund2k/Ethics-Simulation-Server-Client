#include "hw7thing.h"
#include "hw7common.h"
using namespace std;

Thing::Thing(){} // empty constructor

Thing::Thing(string thing){
	this->thing = thing;
}

string Thing::getThing(){
	return this->thing;
}

Json::Value Thing::dump2JSON (void){
    Json::Value result { };

    if (this->thing != ""){
        result["Thing"] = this->thing;
    }

    return result;
}