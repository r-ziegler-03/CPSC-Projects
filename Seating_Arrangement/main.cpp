/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: PA3 Do You See What I See?
*/

/*
Overview:
This file takes a command line argument and stores it as string, it then initializes a SpeakerView object with the string being inputed as the parameter
*/
#include "MonoStack.h"
#include "SpeakerView.h"
#include <iostream>

int main(int argc, char** argv){
    std::string fInput = argv[1];
    SpeakerView test(fInput);
    return 0;
}