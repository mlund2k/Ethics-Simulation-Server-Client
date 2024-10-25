#include "abstractstubserver.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include "server.h"
#include <iostream>

//constructor
myServer::myServer(jsonrpc::AbstractServerConnector &connector,
                           jsonrpc::serverVersion_t type)
    : AbstractStubServer(connector, type) {}

void myServer::alert(){
    std::cout << "Vehicle alerted; ";
    if(getIsCollide()){
        std::cout << "Move!"; // tells vehicle (in this case a motorcycle) to move if it is chosen to be hit
    }
    std::cout << std::endl;
    
    Vehicle.setAlert(true); // notifies intended vehicle of alert status
}

void myServer::setVehicle(const std::string& json_str) {
    Json::Value tempJ;
    
    myParseJSON(json_str, &tempJ);
    
    Vehicle.JSON2Object(tempJ);
}

bool myServer::getIsCollide() {
    return Vehicle.getIsCollide();
}

void myServer::setCollide(bool flag) {
    Vehicle.setCollide(flag);
}

std::string myServer::VehToString() {
    return Vehicle.dump2JSON().toStyledString();
}