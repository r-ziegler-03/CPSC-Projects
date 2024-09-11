#include "Levels.h"
/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: PA2 Not So Super Mario Bros
*/

/*
Overview:
This file dynamically allocates a 2D array representing a level in the mario game
It creates a 2D array of char pointers and populates all of indexes with coins, goombas, koopas, mushrooms, warp pipes, bosses, or empty squares
The file also includes several methods to modoify/update/return parts of the 2D array
*/

/* 
The constructor takes in one int parameter for the dimension of the level
It initializes a char pointer array of the parameter size
Then loops through each indexing initializing a char array of the parameter size
*/
Levels::Levels(int levelSize){
    mLevelSize = levelSize;
    mLevelArr = new char*[mLevelSize];
    for (int i = 0; i < mLevelSize; i++){
        mLevelArr[i] = new char[mLevelSize];
    }
}
/*
The destructor loops through the 2D array and de-allocates it from memory
*/
Levels::~Levels(){
        for (int i = 0; i < mLevelSize;i++){
            delete[] mLevelArr[i];
        }
    delete[] mLevelArr;
}

/*
The populatelevel method takes in 5 parameters being; the probability of a given space on the grid being a coin, goomba, koopa, empty, or mushroom
It then adds a certain number of each entity based on the probabilities to the 2D array at random locations
This method also adds a boss to the 2D array
Lastly it adds a warp pipe to the 2D array as long as it is not the last level of the game
*/
void Levels::populateLevel(int coinProb, int emptProb, int goombaProb, int koopaProb, int mushroomProb){
    int numTotalSquares = mLevelSize * mLevelSize;
    int numCoins = (numTotalSquares-2) * (coinProb / 100.0);
    int numGoomba = (numTotalSquares-2) * (goombaProb / 100.0);
    int numKoopa = (numTotalSquares-2) * (koopaProb / 100.0);
    int numMushroom = (numTotalSquares-2) * (mushroomProb / 100.0);
    // https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/# for how to use random number generator
    int randRow = rand()%mLevelSize;
    int randCol = rand()%mLevelSize;
    mLevelArr[randRow][randCol] = 'b';

    if (!isLastLevel){
        while (true){
            randRow = rand()%mLevelSize;
            randCol = rand()%mLevelSize;
            if (mLevelArr[randRow][randCol] == '\0'){
                mLevelArr[randRow][randCol] = 'w';
                break;
            }
        }
    }
    while (numCoins > 0){
        randRow = rand()%mLevelSize;
        randCol = rand()&mLevelSize;
        if (mLevelArr[randRow][randCol] == '\0'){
            mLevelArr[randRow][randCol] = 'c';
            --numCoins;
        }
    }
    while (numGoomba > 0){
        randRow = rand()%mLevelSize;
        randCol = rand()&mLevelSize;
        if (mLevelArr[randRow][randCol] == '\0'){
            mLevelArr[randRow][randCol] = 'g';
            --numGoomba;
        }
    }
    while (numKoopa > 0){
        randRow = rand()%mLevelSize;
        randCol = rand()&mLevelSize;
        if (mLevelArr[randRow][randCol] == '\0'){
            mLevelArr[randRow][randCol] = 'k';
            --numKoopa;
        }
    }
    while (numMushroom > 0){
        randRow = rand()%mLevelSize;
        randCol = rand()&mLevelSize;
        if (mLevelArr[randRow][randCol] == '\0'){
            mLevelArr[randRow][randCol] = 'm';
            --numMushroom;
        }
    }

    for (int row = 0; row < mLevelSize; row++){
        for (int col = 0; col < mLevelSize; col++){
            if (mLevelArr[row][col] == '\0'){
                mLevelArr[row][col] = 'x';
            }
        }
    }

}

/*
Displays the 2D array as a string 
returns a string
*/
std::string Levels::display(){
    std::string line = "";
    for (int row = 0; row < mLevelSize; row++){
        for (int col = 0; col < mLevelSize; col++){
            line += mLevelArr[row][col];
            line += " ";
        }
        line += "\n";
    }
    return line;
}

/*
This method changes the value at a given (row,col) to a new value
The row,col, and new value are the parameters to the method
*/
void Levels::updateSquare(int row, int col, char item){
    mLevelArr[row][col] = item;
}

/*
This method returns an int
It loops through the 2D array and finds the location where the value is an 'H', in which case it returns the row as an int value
*/
int Levels::getHeroRow(){
    for (int row = 0; row < mLevelSize; row++){
        for (int col = 0; col < mLevelSize; col++){
            if (mLevelArr[row][col] == 'H'){
                return row;
            }
        }
    }
}

/*
This method returns an int
It loops through the 2D array and finds the location where the value is an 'H', in which case it returns the col as an int value
*/
int Levels::getHeroCol(){
    for (int row = 0; row < mLevelSize; row++){
        for (int col = 0; col < mLevelSize; col++){
            if (mLevelArr[row][col] == 'H'){
                return col;
            }
        }
    }
}

/*
This method accesses the 2D array and searches for an index that has the value 'H'
in which case it sets that indexes value to be 'x'
*/
void Levels::removeHero(){
    for (int row = 0; row < mLevelSize; row++){
        for (int col = 0; col < mLevelSize; col++){
            if (mLevelArr[row][col] == 'H'){
                mLevelArr[row][col] = 'x';
            }
        }
    }
}

/*
returns the dimension of the 2D array as an integer value
*/
int Levels::getLevelSize(){
    return mLevelSize;
}

/*
returns the character in the 2D array the index (row,col)
This method takes two integer parameters, int and col
*/
char Levels::getItem(int row, int col){
    return mLevelArr[row][col];
}

/*
This method sets the boolean isLastLevel to be true
when this is used it tells the populatelevel method to not place a 'w' on the grid because this level will be the last level
*/
void Levels::setLastLevel(){
    isLastLevel = true; 
}