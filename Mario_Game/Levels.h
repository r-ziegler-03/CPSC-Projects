#ifndef LEVELS_H
#define LEVELS_H

#include <iostream>
#include <cstdlib>
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

class Levels{
    public:
        /* 
        The constructor takes in one int parameter for the dimension of the level
        It initializes a char pointer array of the parameter size
        Then loops through each indexing initializing a char array of the parameter size
        */
        Levels(int levelSize);
        /*
        The destructor loops through the 2D array and de-allocates it from memory
        */
        ~Levels();
        /*
        The populatelevel method takes in 5 parameters being; the probability of a given space on the grid being a coin, goomba, koopa, empty, or mushroom
        It then adds a certain number of each entity based on the probabilities to the 2D array at random locations
        This method also adds a boss to the 2D array
        Lastly it adds a warp pipe to the 2D array as long as it is not the last level of the game
        */
        void populateLevel(int coinProb, int emptProb, int goombaProb, int koopaProb, int mushroomProb);
        /*
        This method changes the value at a given (row,col) to a new value
        The row,col, and new value are the parameters to the method
        */
        void updateSquare(int row, int col, char item);
        /*
        This method returns an int
        It loops through the 2D array and finds the location where the value is an 'H', in which case it returns the row as an int value
        */
        int getHeroRow();
        /*
        This method returns an int
        It loops through the 2D array and finds the location where the value is an 'H', in which case it returns the col as an int value
        */
        int getHeroCol();
        /*
        This method accesses the 2D array and searches for an index that has the value 'H'
        in which case it sets that indexes value to be 'x'
        */
        void removeHero();
        /*
        returns the dimension of the 2D array as an integer value
        */
        int getLevelSize();
        /*
        Displays the 2D array as a string 
        returns a string
        */
        std::string display();
        /*
        returns the character in the 2D array the index (row,col)
        This method takes two integer parameters, int and col
        */
        char getItem(int row, int col);
        /*
        This method sets the boolean isLastLevel to be true
        when this is used it tells the populatelevel method to not place a 'w' on the grid because this level will be the last level
        */
        void setLastLevel();
    private:
        char** mLevelArr;
        int mLevelSize;
        int mNumLevels;
        bool isLastLevel = false;

};

#endif