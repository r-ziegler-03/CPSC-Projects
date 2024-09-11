/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: PA3 Do You See What I See?
*/

/*
Overview:
This file outputs to the terminal how many people given a text file of heights for the seating arrangement of an event can see the stage
It reads the text file and builds a 2d array to hold the values
Puts those heights into their respective monostacks
Outputs the values that are contained within the monostack
*/

#ifndef SPEAKER_VIEW_H
#define SPEAKER_VIEW_H

#include <string>
#include <iostream>
#include <fstream>
#include "MonoStack.h"

class SpeakerView{
    public:
    SpeakerView(std::string fInput); //constructor, Param: string for the input files name
    ~SpeakerView(); // destructor, deletes the seating 2d array and closes the input file
    int getNumCol(std::string fName); // counts the number of columns in the input file, Param: string for the input files name
    int getNumRows(std::string fName); // counts the number of rows in the input file, Param: string for the input files name
    void create2DArray(std::string fName); // creates the 2d array, populating the rows/columns with the values from the input file, Param: string for the input files name
    void CreateSeating(); /* creates a monostack, goes through each column pushing all of the values into the monostack,
    outputs the values that are in the monostack after it has gone through the whole column*/
    private:
        int mNumCol; // holds the value for the number of columns in the input file
        int mNumRows; // hold the value for the number of rows in the input file
        std::ifstream inFS; // creates an input files stream object
        double** seating; // creates a 2d array of type double

};

#endif