# Ethics-Simulation-Server-Client


This is a program that utilizes servers and clients to simulate pseudocode for an artificial intelligence ethics problem. It simulates where would a car collide against based on the AI's decision to keep the driver safe.


The situation is the following: The car driving in the middle of the road is behind a truck carrying cargo. Somehow the cargo is dislodged and begins to fall toward the car on the center. The car on the center has two motorcycles on both of its sides. Using the algorithms in the AI it must make an unethical but necessary decision.


The car in the middle chooses to swerve to the right or left motorcycle based on the attributes of the people at the sides. We check for arbitrary attributes such as their age, criminal record, number of family members etc.
These values can be tweaked in ```hw7myCar.cpp```

This program was compiled using Mac, Linux, and WSL (Windows Subsystem for Linux) on Windows 10/11 and runs perfectly in such environments.
**How to run:**
Have your terminal open
Open three tabs/windows, all of them on the directory "finalv2"
enter ```make``` in one of the tabs
On the left tab enter ```./left```, on right one enter ```./right``` and on middle one enter ```./myCar```


DISCLAIMER: If program isn't working as expected, close the servers, do ```make clean``` and then ```make``` once again.
If these steps are not followed closely it will likely lead to an error by design.


If compiling raises a fatal error on ```#include <json/json.h>```, make sure to run the following commands to install json on your computer:
```sudo apt-get install libjsoncpp-dev```
```sudo ln -s /usr/include/jsoncpp/json/ /usr/include/json```
Credits: https://github.com/stardust95/TinyCompiler/issues/2#issuecomment-410946235
