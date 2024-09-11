#ifndef SIM_GAME_H
#define SIM_GAME_H
#include "Hero.h"
#include <iostream>
#include <fstream>
/*
Name: Ross Ziegler
ID Number: 2414809
Email: rziegler@chapman.edu
Section: CPSC 350 -04
Assignment: PA2 Not So Super Mario Bros
*/

/*
Overview:
This file simulates the mario game
It creates an array of Levels pointers, which contains all of the levels mario will traverse
It then runs through the logic of the game by...
having mario, move on the grid, interact with different indexes, traverse levels, and fight enemies
After every turn it is also checking to see if mario has lost or won the game
*/

class SimGame{
    public:
        /*
        This is the constructor
        it takes in 8 parameters: levels (the number of levels mario will traverse), dimension (the length of the mario rows and cols),
        numLives (the number of lives mario will start with), *Prob (the probability for that item populating an index in the level)
        Within this constructor a Hero object is initialized with numLives
        The world of levels is created
        */
        SimGame(int numLevels, int dimension, int numLives ,int coinProb, int emptProb, int goombaProb, int koopaProb, int mushroomProb);
        /*
        This is the destructor for SimGame
        it de-allocates the world array
        */
        ~SimGame();
        /*
        This method is the main logic for running the simulation
        It places mario on the grid by calling the necessary functions
        It runs through a move made by mario checking to see whether he is still alive and/or he passed his current level
        It checks to see if mario won the game
        It logs all of marios moves to a log.txt file
        */
        void runGame();
        /*
        This takes in a integer parameter for the direction mario wants to move (0 = left, 1 = right, 2 = up, 3 = down)
        it then returns as a char value, the item at the sqaure mario wants to move to
        it also checks to see if mario is on a edge of the level, in which case he will wrap around to the other side
        */
        char moveHero(int dir);
        /*
        This method takes a char parameter
        it checks what item is on the sqaure mario wants to move to
        Depending on what the item is, it runs the necessary logic
        This also outoputs to the log file
        */
        void interact(char c);
        /*
        This takes a char parameter 
        if the char is a g, mario is going to fight a goomba, in which case it runs the necessary logic
        if the char is a k, mario is going to fight a koopa, in which case it runs the necessary logic
        */
        void fight(char enemy);
        /*
        This method runs the necessary logic to carry out a boss fight
        if mario loses and he is out of lives he loses the game
        if he loses but has lifes to spare he continues fighting the boss
        if he wins, he moves onto the next level, unless it is the last level, in which case he has won the game
        */
        void bossFight();

    private:
        Hero* mario;
        Levels** world;
        bool levelPassed = false;
        bool gameOver = false;
        bool gameWon = false;
        bool repeatBoss = false;
        int currentLevel;
        char moveTo;
        int row;
        int col;
        int numLevels;
        std::ofstream outputLog;
};

#endif