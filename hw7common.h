#ifndef _COMMON_H_
#define _COMMON_H_
//file that has the includes
// ecs36b_Common.h

#include <string.h>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <exception>
#include <sstream>
#include <exception>
#include <stdlib.h>
#include <list>

// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

// global JSON functions
//int myFile2JSON(char *f_name, Json::Value * jv_ptr);
int myJSON2File(char *f_name, Json::Value * jv_ptr); 
int myParseJSON(std::string input, Json::Value * jv_ptr);
char *myFile2String(char *f_name);

using namespace std;

#define LEFT_MCYCLE_PORT 1234
#define RIGHT_MCYCLE_PORT 4321

#endif