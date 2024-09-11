#include "Hero.h"
/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: PA2 Not So Super Mario Bros
*/

/*
Overview:
This file creates a Hero which will be mario
The Hero class contains 4 attributes, their number of lives, current power level, number of coins collected, and number of enemies defeated
*/

// The constructor takes in an int parameter for the number of lives, the member variable for number of lives is initialized to that value.
// current power level, number of coins collected, and number of enemies defeated are initialized to 0
Hero::Hero(int numLives){
    mNumLives = numLives;
    mCurrPowLevel = 0;
    mNumCoinsCollected = 0;
    mNumEnemiesDefeated = 0;
}

// The destructor for the Hero class
Hero::~Hero(){
}

// Generates a random number 0 to 3 and returns that integer
// This will be used to choose the direction the hero moves on the level
int Hero::move(){
    int direction = rand()%4;
    return direction;
}

// Returns the integer value of the Heros current power level
int Hero::getCurrPowerLevel(){
    return mCurrPowLevel;
}
// Sets the Heros current power level to be whatever is put in the integer parameter
void Hero::setCurrPowerLevel(int num){
    mCurrPowLevel = num;
}

// Returns the integer value of the number of coins the Hero has collected
int Hero::getNumCoinsCollected(){
    return mNumCoinsCollected;
}
// Sets the number of Coins the Hero has collected to be whatever is put in the integer parameter
void Hero::setNumCoinsCollected(int num){
    mNumCoinsCollected = num;
}

// Returns the integer value of the number of enemies the Hero has defeated
int Hero::getNumEnemiesDefeated(){
    return mNumEnemiesDefeated;
}
// Sets the number of enemies the Hero has defeated to be whatever is put in the integer parameter
void Hero::setNumEnemiesDefeated(int num){
    mNumEnemiesDefeated = num;
}

// Returns the integer value of the number of lives the Hero has
int Hero::getNumLives(){
    return mNumLives;
}
// Sets the number of lives the Hero has to be whatever is put in the integer parameter
void Hero::setNumLives(int num){
    mNumLives = num;
}
