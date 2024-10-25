#include "hw7autov.h"
#include "hw7common.h"

using namespace std;

AutoV::AutoV(){} // empty constructor

AutoV::AutoV(Person & driver, double speed, double width, Place & place){
	this->driver = driver;
    this->speed = speed;
	this->width = width;
	this->position = place;
}

double AutoV::getSpeed(){
	return this->speed;
}

double AutoV::getWidth(){
	return this->width;
}

Place AutoV::getPosition(){
	return this->position;
}

Person AutoV::getDriver(){
    return this->driver;
}

Json::Value AutoV::dump2JSON (void){
    Json::Value result { };

    if (this->speed >= 0){
        result["speed"] = this->speed;
    }
    if (this->width > 0){
        result["width"] = this->width;
    }

    Json::Value jv_result;
    jv_result = driver.dump2JSON();
    result["driver"] = jv_result;

    jv_result = position.dump2JSON();
    result["Place"] = jv_result;

    return result;
}

bool AutoV::JSON2Object(Json::Value arg){
    if((arg.isNull() == true) || (arg.isObject() != true)){
        return false;
    }
    if(((arg["speed"]).isNull() == true) || ((arg["speed"]).isDouble() != true)){
        return false;
    }
    if(((arg["width"]).isNull() == true) || ((arg["width"]).isDouble() != true)){
        return false;
    }
    
    if(((arg["driver"]).isNull() == true) || ((arg["driver"]).isObject() != true)){
        return false;
    }
    this->speed = (arg["speed"]).asDouble();
    this->width = (arg["width"]).asDouble();

    Person emptyPerson;
    if (emptyPerson.JSON2Object(arg["driver"])) {
        this->driver = emptyPerson;
    }

    Place emptyPlace;
    if(emptyPlace.JSON2Object(arg["Place"])){
        this->position = emptyPlace;
    }    
    return true;
}