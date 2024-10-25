#include "hw7place.h"
#include "hw7common.h"
using namespace std;

Place::Place(){} // empty constructor

Place::Place(double longitude, double lat){
	this->longitude = longitude;
    this->latitude = lat;
}

double Place::getLongitude(){
    return this->longitude;
}
double Place::getLatitude(){
    return this->latitude;
}

Json::Value Place::dump2JSON (void){
    Json::Value result { };

    if (this->longitude >= 0.0){
        result["Longitude"] = this->longitude;
    }
    if (this->latitude >= 0.0){
        result["Latitude"] = this->latitude;
    }

    return result;
}

bool Place::JSON2Object(Json::Value arg){
    if((arg.isNull() == true) || (arg.isObject() != true)){
        return false;
    }
    if(((arg["Longitude"]).isNull() == true) || ((arg["Longitude"]).isDouble() != true)){
        return false;
    }
    if(((arg["Latitude"]).isNull() == true) || ((arg["Latitude"]).isDouble() != true)){
        return false;
    }

    this->longitude = (arg["Longitude"]).asDouble();
    this->latitude = (arg["Latitude"]).asDouble();
    
    return true;
}