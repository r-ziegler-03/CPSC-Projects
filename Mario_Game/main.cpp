#include "Levels.h"
#include "SimGame.h"
#include <fstream>
#include <iostream>
/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: PA2 Not So Super Mario Bros
*/

/*
Overview:
The main takes in a command line argument to read in the values for the Simgame constructor
A SimGame object is created with the constructor values being assigned the values from the read in input file
*/

int main(int argc, char** argv){
    // read in values from command line
    // create sim game object with those values
    // call run game
    //https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/# for how to generate a new seed with random number generator
    srand(time(NULL));
    std::string fInput = argv[1];
    std::ifstream iFile(fInput);
    int levels, dimension, numLives , coinProb, emptProb, goombaProb, koopaProb, mushroomProb;
    iFile >> levels >> dimension >> numLives >> coinProb >> emptProb >> goombaProb >> koopaProb >> mushroomProb;
    SimGame marioSim(levels,dimension,numLives,coinProb,emptProb,goombaProb,koopaProb,mushroomProb);
    marioSim.runGame();
    iFile.close();
    return 0;
}