#ifndef HERO_H
#define HERO_H
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
This file creates a Hero which will be mario
The Hero class contains 4 attributes, their number of lives, current power level, number of coins collected, and number of enemies defeated
*/
class Hero{
    public:
        // The constructor takes in an int parameter for the number of lives, the member variable for number of lives is initialized to that value.
        // current power level, number of coins collected, and number of enemies defeated are initialized to 0
        Hero(int numLives);
        // The destructor for the Hero class
        ~Hero();
        // Generates a random number 0 to 3 and returns that integer
        // This will be used to choose the direction the hero moves on the level
        int move();
        // Returns the integer value of the number of lives the Hero has
        int getNumLives();
        // Sets the number of lives the Hero has to be whatever is put in the integer parameter
        void setNumLives(int num);
        // Returns the integer value of the Heros current power level
        int getCurrPowerLevel();
        // Sets the Heros current power level to be whatever is put in the integer parameter
        void setCurrPowerLevel(int num);
        // Returns the integer value of the number of coins the Hero has collected
        int getNumCoinsCollected();
        // Sets the number of Coins the Hero has collected to be whatever is put in the integer parameter
        void setNumCoinsCollected(int num);
        // Returns the integer value of the number of enemies the Hero has defeated
        int getNumEnemiesDefeated();
        // Sets the number of enemies the Hero has defeated to be whatever is put in the integer parameter
        void setNumEnemiesDefeated(int num);
    private:
        int mNumLives;
        int mCurrPowLevel;
        int mNumCoinsCollected;
        int mNumEnemiesDefeated;

};
#endif