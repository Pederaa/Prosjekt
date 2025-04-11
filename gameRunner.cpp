#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include "gameRunner.h"
#include "Bomb.h"
#include "numBomb.h"
#include "textBomb.h"
#include "readKeyInput.h"
#include "backgroundGenerator.h"
#include "typingScreen.h"
#include "eggsManager.h"
#include "laserCannon.h"
#include <bits/stdc++.h>
#include "explotionManager.h"
#include <random>
#include "constants.h"
#include "LaserTurtleWindow.h"

std::list<Bomb> bombs;
std::list<Explotion> explotions;
std::list<Laser> lasers;
laserCannon l(1,2);

constexpr int n = sizeof(BEGIN_LANES)/sizeof(int);
vector<int> lanes;
static int bombsSpawned = 0;
static int delayEndFrames = 0;

void runGame(LTWindow& window){
    random_device rd;
    default_random_engine generator(rd());
    std::string typeText = "";

    copy(&BEGIN_LANES[0], &BEGIN_LANES[n], back_inserter(lanes));

    initlizeEggs(lanes);
    l.setBaseposition(LASER_CANNON_X, LASER_CANNON_Y);
    l.pointCannonUp();

    bool gameOver = false;
    bombsSpawned = 0;
    delayEndFrames = 0;
    while(!window.should_close() && !gameOver){
        addBombs(generator, lanes);
        drawBackground(window);
        drawBombs(window);
        drawEggs(window);
        drawLasers(window);
        l.drawCannon(window);
        drawTurtle(window);
        drawExplotions(window);
        drawTypingScreen(window, typeText);
        getCharInput(window, typeText);

        checkIfGameOver(window, gameOver);

        window.next_frame();
    }
    
    cout << "Spill over" << endl;
}

int bombaddingIterator = 0;
void addBombs(std::default_random_engine& generator, vector<int> lanes){
    if (bombsSpawned < MAX_NUMBER_OF_BOMBS){
        if (bombaddingIterator == 80){
            bombsSpawned++;
            if (generator()%1 == 0){
                textBomb newBomb = textBomb(lanes);
                bombs.push_back(newBomb);
                bombaddingIterator = 0;
                return;
            } else{
                numBomb newBomb = numBomb(lanes);
                bombs.push_back(newBomb);
                bombaddingIterator = 0;
                return;
            }
        }
        bombaddingIterator++;
    }
    else{
        if (bombs.size() == 0){
            delayEndFrames++;
        }
    }
}

void drawBombs(TDT4102::AnimationWindow& window){
    /*Her itererer vi over alle blokkelementene. Vi flytter alle et hakk ned 
    og sletter de som har kommet for langt. Her må vi bruke en while-løkke. 
    Mer info: https://www.geeksforgeeks.org/cpp-remove-elements-from-a-list-while-iterating/
    */
    list<Bomb>::iterator it = bombs.begin();
    while (it != bombs.end()){
        (*it).moveDown(window);
        if ((*it).posY() >= getHeightOfeggs() - 100){
            explotions.push_back(Explotion((*it).posX(), (*it).posY()));
            damageEggAtXPosition((*it).posX());
            it = bombs.erase(it);
            continue;
        }
        it++;
    }
}

bool checkIfGuessIsCorrect(std::string guess){
    if (bombs.size() == 0){
        return false;
    }

    // Her går det fint med en for-løkke siden vi går ut av løkka med en gang den finne den som passer
    for (auto it = bombs.begin(); it != bombs.end(); it++){
        if(guess == (*it).Answer()){
            l.pointCannonAt((*it).posX(), (*it).posY());
            explotions.push_back(Explotion((*it).posX(), (*it).posY()));
            lasers.push_back(Laser(l, (*it)));
            bombs.erase(it);
            return true;
        }
    }
    return false;
}

void drawExplotions(TDT4102::AnimationWindow& window){
    list<Explotion>::iterator it = explotions.begin();
    while (it != explotions.end()){
        bool isExplotionDone = (*it).drawExplotion(window);

        if (isExplotionDone){
            it = explotions.erase(it);
            continue;
        }
        it++;
    }
}

void drawLasers(TDT4102::AnimationWindow& window){
    list<Laser>::iterator it = lasers.begin();
    while (it != lasers.end()){
        bool isLaserDone = (*it).drawLaser(window);
        if (isLaserDone){
            it = lasers.erase(it);
            continue;
        }
        it++;
    }
}

void removeLineAtX(int x){
    for (unsigned long long i = 0; i < lanes.size(); i++){
        if(lanes.at(i) == x){
            lanes.erase(lanes.begin() + i);
            break;
        }
    }

    auto it = bombs.begin();
    while (it != bombs.end()){
        if ((*it).posX() == x - 50){
            explotions.push_back(Explotion((*it).posX(), (*it).posY()));
            eraseEgg((*it).posX());
            it = bombs.erase(it);
            continue;
        }
        it++;
    }
}

void checkIfGameOver(LTWindow& window, bool& gameOver){
    if(lanes.size() == 0 && delayEndFrames >= 30){
        gameOver = true;
        window.currentPageMode = pageMode::frontpage;
        return;
    }
    else if(bombsSpawned >= MAX_NUMBER_OF_BOMBS && bombs.size() == 0 && delayEndFrames >= 30){
        gameOver = true;
        window.currentPageMode = pageMode::frontpage;
        return;
    }
}