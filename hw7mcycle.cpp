#include "hw7mcycle.h"
#include "hw7common.h"
using namespace std;

MCycle::MCycle(){} // empty constructor

MCycle::MCycle(Person & rider, double speed, double width, Place & place){
	this->driver = rider;
    this->speed = speed;
	this->width = width;
	this->position = place;
}

bool MCycle::getIsAlert(){
    return this->isAlert;
}

bool MCycle::getIsCollide(){
    return this->isCollide;
}

void MCycle::setAlert(bool flag){
    this->isAlert = flag;
}

void MCycle::setCollide(bool flag){
    this->isCollide = flag;
}

Person MCycle::getDriver(){
    return this->driver;
}

Json::Value MCycle::dump2JSON (void){
    Json::Value result { };

    if (this->speed >= 0){
        result["speed"] = this->speed;
    }
    if (this->width > 0){
        result["width"] = this->width;
    }

    Json::Value jv_result;

    jv_result = position.dump2JSON();
    result["Place"] = jv_result;

    jv_result = driver.dump2JSON();
    result["Rider"] = jv_result;

    return result;
}

bool MCycle::JSON2Object(Json::Value arg) {
    if((arg.isNull() == true) || (arg.isObject() != true)){
        return false;
    }
    if(((arg["speed"]).isNull() == true) || ((arg["speed"]).isDouble() != true)){
        return false;
    }
    if(((arg["width"]).isNull() == true) || ((arg["width"]).isDouble() != true)){
        return false;
    }
    
    Place emptyPlace;
    Person emptyPerson;

    if(emptyPlace.JSON2Object(arg["Place"])){
        this->position = emptyPlace;
    }
    if(emptyPerson.JSON2Object(arg["Rider"])){
        this->driver = emptyPerson;
    }

    this->speed = (arg["speed"]).asDouble();
    this->width = (arg["width"]).asDouble();


    return true;
}