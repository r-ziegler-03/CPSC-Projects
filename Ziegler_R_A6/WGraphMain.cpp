/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: PA6 Kruskals
*/

/*
Overview:
This file takes a command line argument which is used to open a text file
the text file is read until it reaches the delimiting word "END"
A WGraph object is made and has edges added as the text file is looped through
It then computes the MST and closes the text file
*/
#include "WGraph.h"
#include <iostream>
#include <fstream>

int main(int argc, char** argv){
    // String to hold the text file given by the command line argument
    std::string fInput = argv[1];
    // opens the text file given using ifstream object
    std::ifstream iFile(fInput);
    // creates an integer variable to store the size of the matrix when the WGraph object is instantiated
    int sizeOfMatrix;
    // Reads the first element in the text file and stores it into sizeOfMatrix
    iFile >> sizeOfMatrix;
    // Creates a WGraph object with the size being sizeOfMatrix
    WGraph myWG(sizeOfMatrix);
    // creates a double variable to store the weights of the edges that will be read from the text file
    double weights;
    // Loops through the top half of the diagonal in the text file and adds the edges accordingly
    for (int i = 0; i < sizeOfMatrix - 1; i++){
        for (int j = 0; j < sizeOfMatrix; j++){
            iFile >> weights;
            if ((j > (i+1)) || (weights != 0)){
                myWG.addEdge(i,j,weights);
            }

        }
    }
    // closes the text file
    iFile.close();
    // calls the method to compute the MST
    myWG.computeMST();

  return 0;
}