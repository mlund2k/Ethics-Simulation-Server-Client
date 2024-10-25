#pragma once
//abstractstubserver.h is created by using make
#include "abstractstubserver.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include "hw7person.h"
#include "hw7thing.h"
#include "hw7autov.h"
#include "hw7mcycle.h"

class myServer : public AbstractStubServer {
    private:
        MCycle Vehicle;
    public:
        myServer(jsonrpc::AbstractServerConnector &connector,
                           jsonrpc::serverVersion_t type);
        void alert(); // alerts vehicle
        void setVehicle(const std::string& json_str); // creates vehicle in server
        bool getIsCollide();
        void setCollide(bool flag); // used to tell other vehicles you will hit them
        std::string VehToString();
};