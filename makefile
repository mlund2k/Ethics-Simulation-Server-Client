CC = g++ -std=c++14
CFLAGS = -g

LDFLAGS = 	 -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl
INC_CL	=	hw7ecs36b_Exception.h hw7common.h hw7place.h hw7person.h hw7thing.h hw7autov.h hw7car.h hw7mcycle.h hw7truck.h
OBJ	=	server.o client.o hw7leftMotorcycle.o hw7rightMotorcycle.o hw7place.o hw7person.o hw7ecs36b_JSON.o hw7thing.o hw7car.o hw7autov.o hw7truck.o hw7mcycle.o
# rules.
all: myCar left right

MYCARF = server.o hw7place.o hw7person.o hw7ecs36b_JSON.o hw7thing.o hw7car.o hw7autov.o hw7truck.o hw7mcycle.o hw7myCar.o
myCar: $(MYCARF)
	$(CC) $(MYCARF) $(LDFLAGS) -o myCar

LEFTF = server.o hw7place.o hw7person.o hw7ecs36b_JSON.o hw7thing.o hw7car.o hw7autov.o hw7truck.o hw7mcycle.o hw7leftMotorcycle.o
left: $(LEFTF)
	$(CC) $(LEFTF) $(LDFLAGS) -o left

RIGHTF = server.o hw7place.o hw7person.o hw7ecs36b_JSON.o hw7thing.o hw7car.o hw7autov.o hw7truck.o hw7mcycle.o hw7rightMotorcycle.o
right: $(RIGHTF)
	$(CC) $(RIGHTF) $(LDFLAGS) -o right

hw7myCar.o: hw7myCar.cpp
	$(CC) -c $(CFLAGS) hw7myCar.cpp

hw7leftMotorcycle.o: hw7leftMotorcycle.cpp
	$(CC) -c $(CFLAGS) hw7leftMotorcycle.cpp

hw7rightMotorcycle.o: hw7rightMotorcycle.cpp
	$(CC) -c $(CFLAGS) hw7rightMotorcycle.cpp

hw7place.o: hw7place.cpp
	$(CC) -c $(CFLAGS) hw7place.cpp

hw7person.o: hw7person.cpp
	$(CC) -c $(CFLAGS) hw7person.cpp

hw7thing.o: hw7thing.cpp
	$(CC) -c $(CFLAGS) hw7thing.cpp

hw7autov.o: hw7autov.cpp
	$(CC) -c $(CFLAGS) hw7autov.cpp

hw7car.o: hw7car.cpp
	$(CC) -c $(CFLAGS) hw7car.cpp

hw7mcycle.o: hw7mcycle.cpp
	$(CC) -c $(CFLAGS) hw7mcycle.cpp

hw7truck.o: hw7truck.cpp
	$(CC) -c $(CFLAGS) hw7truck.cpp

hw7ecs36b_JSON.o: hw7ecs36b_JSON.cpp
	$(CC) -c $(CFLAGS) hw7ecs36b_JSON.cpp

server.o: abstractstubserver.h
	$(CC) -c $(CFLAGS) server.cpp

abstractstubserver.h stubclient.h: spec.json
	jsonrpcstub spec.json --cpp-server=AbstractStubServer --cpp-client=StubClient

clean:
	rm -f *.o *~ myCar left right stubclient.h abstractstubserver.h