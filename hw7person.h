#ifndef _PERSON_H_
#define _PERSON_H_
#include "hw7common.h"
using namespace std;

class Person{
    private:
        string name;
        int age;
        bool isCriminalRecord; // returns true if person has criminal history
        string occupation;
        int familyMembers;
    public:
        string getName(); // accessor functions
        int getAge();
        bool getIsCriminalRecord();
        string getOccupation();
        int getFamily();
        
        Person(); // constructors
        Person(string,int,bool,string,int);
        
        virtual Json::Value dump2JSON(); // JSON functions
        virtual bool JSON2Object(Json::Value);
};

#endif