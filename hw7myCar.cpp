#include "hw7autov.h"
#include "hw7car.h"
#include "hw7mcycle.h"
#include "hw7place.h"
#include "hw7person.h"
#include "hw7thing.h"
#include "hw7truck.h"

#include "hw7common.h"

#include <iostream>
#include "server.h"
#include "stubclient.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <jsonrpccpp/client/connectors/httpclient.h>
using namespace std;
int main(){
    jsonrpc::HttpClient leftClient("http://localhost:" + std::to_string(LEFT_MCYCLE_PORT));
    // left client initialized, to communicate with left server
    StubClient leftC(leftClient, jsonrpc::JSONRPC_CLIENT_V2);

    jsonrpc::HttpClient rightClient("http://localhost:" + std::to_string(RIGHT_MCYCLE_PORT));
    // right client initialized, to communicate with right server
    StubClient rightC(rightClient, jsonrpc::JSONRPC_CLIENT_V2);

    // create vehicle locations
    Place loc_car{500.0, 600.0};
    Place loc_lcycle{490.0, 600.0};
    Place loc_rcycle{510.0, 600.0};
    Place loc_semi{500.0, 620.0};

    // create cargo object
    Thing Cargo{"stuff"};
    
    // creates person objects involved (name, age, criminal status, occupation, family members)
    Person Bob{"Bob", 40, false, "Hustler", 12};
    Person Joe{"Joe", 50, false, "Teacher", 16};
    Person Bart{"Bart", 45, false, "Truck driver", 8};
    Person Richard{"Richard", 40, true, "Tiktoker", 4};
    Person Dan{"Dan", 30, true, "Tiktoker", 4};

    // objects for each of the vehicles involve
    Car myCar{Bob, 60.0, 7.0, loc_car};
    MCycle LeftCycle{Richard, 60.0, 3.0, loc_lcycle};
    MCycle RightCycle{Dan, 90.0, 2.5, loc_rcycle};
    Truck Semi{Bart, 55.0, 10.0, loc_semi, Cargo, false};
    
    //std::cout << "Left cycle is " << LeftCycle.dump2JSON().toStyledString() << std::endl;
    //std::cout << "Right cycle is " << RightCycle.dump2JSON().toStyledString() << std::endl;

    // creates vehicles objects as received from server
    leftC.setVehicle(LeftCycle.dump2JSON().toStyledString());
    rightC.setVehicle(RightCycle.dump2JSON().toStyledString());

    // if the semi's cargo is no longer intact
    if (!(Semi.getIsCargo())){
        leftC.alert(); // alert both motorcycles
        rightC.alert();

        std::cout <<  "Left motorcycle situation:\n" << leftC.VehToString() << std::endl;
        std::cout <<  "Right motorcycle situation:\n" << rightC.VehToString() << std::endl;

        // convert json information to objects
        Json::Value temp;
        myParseJSON(leftC.VehToString(), &temp);
        MCycle infoLCycle;
        infoLCycle.JSON2Object(temp);
        MCycle infoRCycle;
        myParseJSON(rightC.VehToString(), &temp);
        infoRCycle.JSON2Object(temp);
        
        // Use person attributes from given cyclist information to determine who to hit
        if(infoLCycle.getDriver().getIsCriminalRecord() && 
            infoLCycle.getDriver().getIsCriminalRecord()!= infoRCycle.getDriver().getIsCriminalRecord()){
            leftC.setCollide(true);
            leftC.alert();
            cout << "Hit left motorcycle because of criminal record!\n";
        }
        else if(infoRCycle.getDriver().getIsCriminalRecord() && 
            infoLCycle.getDriver().getIsCriminalRecord()!= infoRCycle.getDriver().getIsCriminalRecord()){
            rightC.setCollide(true);
            rightC.alert();
            cout << "Hit right motorcycle because of criminal record!\n";
        }
        else if(infoLCycle.getDriver().getOccupation() == "Tiktoker" && 
        infoRCycle.getDriver().getOccupation() != "Tiktoker"){
            leftC.setCollide(true);
            leftC.alert();
            cout << "Hit left motorcycle because of occupation!\n";
        }
        else if(infoRCycle.getDriver().getOccupation() == "Tiktoker" && 
        infoLCycle.getDriver().getOccupation() != "Tiktoker"){
            rightC.setCollide(true);
            rightC.alert();
            cout << "Hit right motorcycle because of occupation!\n";
        }
        else if(infoLCycle.getDriver().getFamily() != infoRCycle.getDriver().getFamily()){
            if(infoLCycle.getDriver().getFamily() < infoRCycle.getDriver().getFamily()){
                leftC.setCollide(true);
                leftC.alert();
                cout << "Hit left motorcycle because of family!\n";
            }
            else{
                rightC.setCollide(true);
                rightC.alert();
                cout << "Hit right motorcycle because of family!\n";
            }
        }
        else if(infoLCycle.getDriver().getAge() != infoRCycle.getDriver().getAge()){
            if(infoLCycle.getDriver().getAge() > infoRCycle.getDriver().getAge()){
                leftC.setCollide(true);
                leftC.alert();
                cout << "Hit left motorcycle because of age!\n";
            }
            else{
                rightC.setCollide(true);
                rightC.alert();
                cout << "Hit right motorcycle because of age!\n";
            }
        }
        else{
            leftC.setCollide(true);
            leftC.alert();
            cout << "Hit left motorcycle for no particular reason!\n";
        }
    }

    leftC.setCollide(false);
    rightC.setCollide(false);
    return 0;
}