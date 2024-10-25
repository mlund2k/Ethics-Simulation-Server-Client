#include "hw7person.h"
#include "hw7common.h"
using namespace std;

Person::Person(){} // empty constructor

Person::Person(string name, int age, bool flag, string occupation, int fam){
	this->name = name;
	this->age = age;
	this->isCriminalRecord = flag;
    this->occupation = occupation;
    this->familyMembers = fam;
}

string Person::getName(){
	return this->name;
}

int Person::getAge(){
	return this->age;
}

bool Person::getIsCriminalRecord(){
	return this->isCriminalRecord;
}

string Person::getOccupation(){
    return this->occupation;
}

int Person::getFamily(){
    return this->familyMembers;
}

Json::Value Person::dump2JSON (void){
    Json::Value result;

    if (this->name != ""){
        result["Name"] = this->name;
    }
    if (this->age > 0){
        result["Age"] = this->age;
    }
    if ((this->isCriminalRecord) || !(this->isCriminalRecord)){
        result["Criminal Record"] = this->isCriminalRecord;
    }
    if (this->occupation != ""){
        result["Occupation"] = this->occupation;
    }
    if (this->familyMembers >= 0){
        result["Family members"] = this->familyMembers;
    }

    return result;
}

bool Person::JSON2Object(Json::Value arg){
    //if((arg.isNull() == true) || (arg.isObject() != true))
    if(arg.isNull()){
        return false;
    }
    if(((arg["Name"]).isNull() == true) || ((arg["Name"]).isString() != true)){
        return false;
    }
    if(((arg["Age"]).isNull() == true) || ((arg["Age"]).isInt() != true)){
        return false;
    }
    if(((arg["Criminal Record"]).isNull() == true) || ((arg["Criminal Record"]).isBool() != true)){
        return false;
    }
    if(((arg["Occupation"]).isNull() == true) || ((arg["Occupation"]).isString() != true)){
        return false;
    }
    if(((arg["Family members"]).isNull() == true) || ((arg["Family members"]).isInt() != true)){
        return false;
    }

    this->name = (arg["Name"]).asString();
    this->age = (arg["Age"]).asInt();
    this->isCriminalRecord = (arg["Criminal Record"]).asBool();
    this->occupation = (arg["Occupation"]).asString();
    this->familyMembers = (arg["Family members"]).asInt();

    return true;
}