#include "SimGame.h"
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

/*
This is the constructor
it takes in 8 parameters: levels (the number of levels mario will traverse), dimension (the length of the mario rows and cols),
numLives (the number of lives mario will start with), *Prob (the probability for that item populating an index in the level)
Within this constructor a Hero object is initialized with numLives
The world of levels is created
*/
SimGame::SimGame(int levels, int dimension, int numLives ,int coinProb, int emptProb, int goombaProb, int koopaProb, int mushroomProb){
    numLevels = levels;
    mario = new Hero(numLives);
    world = new Levels*[numLevels];
    for (int i = 0; i < numLevels; i++){
        world[i] = new Levels(dimension);
        std::cout << "level created" << std::endl;
        if (i == (numLevels-1)){
            world[i]->setLastLevel();
        }
        world[i]->populateLevel(coinProb,emptProb,goombaProb,koopaProb,mushroomProb);
    }
    currentLevel = 0;
}

/*
This is the destructor for SimGame
it de-allocates the world array
*/
SimGame::~SimGame(){
    for (int i = 0; i < numLevels; i++){
        delete world[i];
    }
    delete[] world;
    delete mario;
    mario = nullptr;
}

/*
This method is the main logic for running the simulation
It places mario on the grid by calling the necessary functions
It runs through a move made by mario checking to see whether he is still alive and/or he passed his current level
It checks to see if mario won the game
It logs all of marios moves to a log.txt file
*/
void SimGame::runGame(){
    int direction;
    outputLog.open("log.txt");
    for (int l = 0; l < numLevels; l++){
        outputLog << world[l]->display();
        outputLog << "\n================\n";
    }
    outputLog << "\n ================= \n";
    for (int i = 0; i < numLevels; i++){
        repeatBoss = false;
        levelPassed = false;
        if (gameOver){
            break;
        }
        int startRow = rand()%world[i]->getLevelSize();
        int startCol = rand()%world[i]->getLevelSize();
        outputLog << "\nMario is starting in position: (" << startRow << "," << startCol << ")";
        char temp = world[i]->getItem(startRow,startCol);
        world[i]->updateSquare(startRow,startCol,'H');
        outputLog << "\n ================= \n";
        outputLog << world[i]->display();
        while (true){
            outputLog << "Level: " << i << ". Mario is at: " << "(" << world[i]->getHeroRow() << "," << world[i]->getHeroCol() << ") ";
            interact(temp);
            if (levelPassed){
                break;
            } else if (gameOver){
                break;
            }
            if (!repeatBoss){
                direction = mario->move();
                temp = moveHero(direction);
                outputLog << '\n';
            }
            world[i]->removeHero();
            world[i]->updateSquare(row,col,'H');
            outputLog << world[i]->display();
            outputLog << std::endl;
        }
        currentLevel++;
        levelPassed = false;
    }
    if (gameWon){
        outputLog << "\n" << "MARIO WON THE GAME";
    } else {
        outputLog << "\n" << "MARIO LOST THE GAME";
    }
    outputLog.close();
}

/*
This method takes a char parameter
it checks what item is on the sqaure mario wants to move to
Depending on what the item is, it runs the necessary logic
This also outoputs to the log file
*/
void SimGame::interact(char c){
    // if g or k
    if (c == 'k' || c == 'g'){
        // call fight(c)
        fight(c);
    }
    // if c
    if (c == 'c'){
        // increase c by 1
        mario->setNumCoinsCollected(mario->getNumCoinsCollected()+1);
        if (mario->getNumCoinsCollected() == 20){
            mario->setNumLives(mario->getNumLives()+1);
            mario->setNumCoinsCollected(0);
        }
        outputLog << "Mario is at power level " << mario->getCurrPowerLevel() << ". Mario collected a coin. Mario has " 
        << mario->getNumLives() << " lives left. Mario has " << mario->getNumCoinsCollected() << " coins. Mario will move ";
    }
    // if m
    if (c == 'm'){
        // increase plvl by 1
        if (mario->getCurrPowerLevel() < 2){
            mario->setCurrPowerLevel(mario->getCurrPowerLevel()+1);
        }
        outputLog << "Mario is at power level " << mario->getCurrPowerLevel() << ". Mario encountered a mushroom. Mario has " 
        << mario->getNumLives() << " lives left. Mario has " << mario->getNumCoinsCollected() << " coins. Mario will move ";
    }
    // if b
    if (c == 'b'){
        // call bossFight()
        bossFight();
    }
    // if w
    if (c == 'w'){
        // next level
        outputLog << "Mario is at power level " << mario->getCurrPowerLevel() << ". Mario encountered a Warp Pipe. Mario has " 
        << mario->getNumLives() << " lives left. Mario has " << mario->getNumCoinsCollected() << " coins. Mario will WARP ";
        levelPassed = true;
    }
    // if empty
    if (c == 'x'){
        outputLog << "Mario is at power level " << mario->getCurrPowerLevel() << ". Mario encountered an empty space. Mario has " 
        << mario->getNumLives() << " lives left. Mario has " << mario->getNumCoinsCollected() << " coins. Mario will move ";
        // nothing
    }
}

/*
This takes in a integer parameter for the direction mario wants to move (0 = left, 1 = right, 2 = up, 3 = down)
it then returns as a char value, the item at the sqaure mario wants to move to
it also checks to see if mario is on a edge of the level, in which case he will wrap around to the other side
*/
char SimGame::moveHero(int dir){
    moveTo = ' ';
    row = 0;
    col = 0;
    switch (dir)  
    {
        case 0:
            if (world[currentLevel]->getHeroCol()==0){
                row = world[currentLevel]->getHeroRow();
                col = world[currentLevel]->getLevelSize()-1;
                moveTo = world[currentLevel]->getItem(row,col);
            } else {
                row = world[currentLevel]->getHeroRow();
                col = world[currentLevel]->getHeroCol()-1;
                moveTo = world[currentLevel]->getItem(row,col);
            }
                outputLog << "LEFT";
                break;

        case 1:
            if (world[currentLevel]->getHeroCol() == world[currentLevel]->getLevelSize()-1){
                row = world[currentLevel]->getHeroRow();
                col = 0;
                moveTo = world[currentLevel]->getItem(row,col);
            } else {
                row = world[currentLevel]->getHeroRow();
                col = world[currentLevel]->getHeroCol()+1;
                moveTo = world[currentLevel]->getItem(row,col);
            }
                outputLog << "RIGHT";
                break;
        case 2:
            if (world[currentLevel]->getHeroRow() == 0){
                row = world[currentLevel]->getLevelSize()-1;
                col = world[currentLevel]->getHeroCol();
                moveTo = world[currentLevel]->getItem(row,col);
            } else {
                row = world[currentLevel]->getHeroRow()-1;
                col = world[currentLevel]->getHeroCol();
                moveTo = world[currentLevel]->getItem(row,col);
            }
                outputLog << "UP";
                break;

        case 3:
            if (world[currentLevel]->getHeroRow() == world[currentLevel]->getLevelSize()-1){
                row = 0;
                col = world[currentLevel]->getHeroCol();
                moveTo = world[currentLevel]->getItem(row,col);
            } else {
                row = world[currentLevel]->getHeroRow()+1;
                col = world[currentLevel]->getHeroCol();
                moveTo = world[currentLevel]->getItem(row,col);
            }
                outputLog << "DOWN";
                break;

        default:
                break;
    }
    return moveTo;
}

/*
This takes a char parameter 
if the char is a g, mario is going to fight a goomba, in which case it runs the necessary logic
if the char is a k, mario is going to fight a koopa, in which case it runs the necessary logic
*/
void SimGame::fight(char enemy){
    if (enemy == 'g'){
        if ((rand()%100+1) <= 80){
            mario->setNumEnemiesDefeated(mario->getNumEnemiesDefeated()+1);
            if (mario->getNumEnemiesDefeated() == 7){
                mario->setNumLives(mario->getNumLives()+1);
            }
            outputLog << "Mario is at power level " << mario->getCurrPowerLevel() << ". Mario fought a goomba and won. Mario has " 
            << mario->getNumLives() << " lives left. Mario has " << mario->getNumCoinsCollected() << " coins. Mario will move ";
        } else { 
            if (mario->getCurrPowerLevel() == 0){
                if (mario->getNumLives()==0){
                    gameOver = true;
                    // lost game
                }
                mario->setNumLives(mario->getNumLives()-1);
            } else {
                mario->setCurrPowerLevel(mario->getCurrPowerLevel()-1);
            }
            mario->setNumEnemiesDefeated(0);
            outputLog << "Mario is at power level " << mario->getCurrPowerLevel() << ". Mario fought a goomba and lost. Mario has " 
            << mario->getNumLives() << " lives left. Mario has " << mario->getNumCoinsCollected() << " coins. Mario will move ";
        }
    } else if (enemy == 'k'){
        if ((rand()%100+1) <= 65){
            mario->setNumEnemiesDefeated(mario->getNumEnemiesDefeated()+1);
            if (mario->getNumEnemiesDefeated() == 7){
                mario->setNumLives(mario->getNumLives()+1);
            }
            outputLog << "Mario is at power level " << mario->getCurrPowerLevel() << ". Mario fought a koopa and won. Mario has " 
            << mario->getNumLives() << " lives left. Mario has " << mario->getNumCoinsCollected() << " coins. Mario will move ";
        } else { 
            if (mario->getCurrPowerLevel() == 0){
                if (mario->getNumLives()==0){
                    gameOver = true;
                    // lost game
                }
                mario->setNumLives(mario->getNumLives()-1);
            } else {
                mario->setCurrPowerLevel(mario->getCurrPowerLevel()-1);
            }
            mario->setNumEnemiesDefeated(0);
            outputLog << "Mario is at power level " << mario->getCurrPowerLevel() << ". Mario fought a koopa and lost. Mario has " 
            << mario->getNumLives() << " lives left. Mario has " << mario->getNumCoinsCollected() << " coins. Mario will move ";
        }
    }
}

/*
This method runs the necessary logic to carry out a boss fight
if mario loses and he is out of lives he loses the game
if he loses but has lifes to spare he continues fighting the boss
if he wins, he moves onto the next level, unless it is the last level, in which case he has won the game
*/
void SimGame::bossFight(){
    if ((rand()%100+1) <= 50){
        mario->setNumEnemiesDefeated(mario->getNumEnemiesDefeated()+1);
        if (mario->getNumEnemiesDefeated()==7){
            mario->setNumLives(mario->getNumLives()+1);
        }
        if (currentLevel == (numLevels-1)){
            gameWon = true;
            gameOver = true;
            //won game
        }
        levelPassed = true;
        outputLog << "Mario is at power level " << mario->getCurrPowerLevel() << ". Mario fought a boss and won. Mario has " 
        << mario->getNumLives() << " lives left. Mario has " << mario->getNumCoinsCollected() << " coins. Mario will move to the next Level";
        // passed level, onto the next
    } else {
        if (mario->getCurrPowerLevel() <= 1){
            if (mario->getNumLives() == 0){
                gameOver = true;
                // lost game
            }
            mario->setNumLives(mario->getNumLives()-1);
        } else {
            mario->setCurrPowerLevel(mario->getCurrPowerLevel()-2);
        }
        mario->setNumEnemiesDefeated(0);
        repeatBoss = true;
        outputLog << "Mario is at power level " << mario->getCurrPowerLevel() << ". Mario fought a boss and lost. Mario has " 
        << mario->getNumLives() << " lives left. Mario has " << mario->getNumCoinsCollected() << " coins. Mario will continue fighting\n";
    }
}