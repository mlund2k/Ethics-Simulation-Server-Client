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

int main() {
    jsonrpc::HttpServer httpserver(RIGHT_MCYCLE_PORT);

    // creates server for right motorcycle
    myServer s(httpserver, jsonrpc::JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
    s.StartListening();
    std::cout << "Hit enter to stop the server" << std::endl;
    getchar();

    s.StopListening();
    return 0;
}