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
#include "SpeakerView.h"
//constructor, Param: string for the input files name
SpeakerView::SpeakerView(std::string fInput){
    mNumRows = 0;
    mNumCol = 0;
    getNumRows(fInput);
    getNumCol(fInput);
    create2DArray(fInput);
    CreateSeating();
}
// destructor, deletes the seating 2d array and closes the input file
SpeakerView::~SpeakerView(){
    if (inFS.is_open()){
        inFS.close();
    }
    for (int i = 0; i < mNumRows;i++){
            delete[] seating[i];
        }
    delete[] seating;
}
// counts the number of columns in the input file, Param: string for the input files name
int SpeakerView::getNumCol(std::string fName){
    inFS.open(fName);
    std::string line;
    std::getline(inFS,line);
    std::getline(inFS,line);
    for (int i = 0; i < line.size(); i++){
        if (line[i] == ' '){
            mNumCol++;
        }
    }
    mNumCol++;
    inFS.close();
    return mNumCol;
}
 // counts the number of rows in the input file, Param: string for the input files name
int SpeakerView::getNumRows(std::string fName){
    inFS.open(fName);
    std::string line;
    std::getline(inFS,line);
    while (!inFS.fail()){
        std::getline(inFS,line);
        mNumRows++;
    }
    mNumRows = mNumRows - 2;
    inFS.close();
    return mNumRows;
}
// creates the 2d array, populating the rows/columns with the values from the input file, Param: string for the input files name
void SpeakerView::create2DArray(std::string fName){
    inFS.open(fName);
    std::string temp;
    inFS >> temp;
    seating = new double*[mNumRows];
    for (int i = 0; i < mNumRows; i++){
        seating[i] = new double[mNumCol];
    }
    double height;
    for (int row = 0; row < mNumRows; row++){
        for (int col = 0; col < mNumCol; col++){
            inFS >> height;
            seating[row][col] = height;
        }
    }
    inFS.close();
}
/* creates a monostack, goes through each column pushing all of the values into the monostack,
    outputs the values that are in the monostack after it has gone through the whole column*/
void SpeakerView::CreateSeating(){
    MonoStack<double>* arrangement = new MonoStack<double>(mNumRows,'d');
    for (int col = 0; col < mNumCol; col++){
        for (int row = mNumRows-1; row >= 0; row--){
            arrangement->push(seating[row][col]);
        }
        std::cout << "In column " << col << " there are " << arrangement->size() << " that can see. Their heights are: ";
        while (!arrangement->isEmpty()){
            std::cout << arrangement->pop() << ", ";
        }
        std::cout << "inches" << std::endl;
    }
    delete arrangement;
}