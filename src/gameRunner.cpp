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

std::list<std::unique_ptr<Bomb>> bombs;
Explotions explotions;
std::list<Laser> lasers;
laserCannon l(1,2);

constexpr int n = sizeof(BEGIN_LANES)/sizeof(int);
vector<int> lanes;

void runGame(LTWindow& window){
    std::string typeText = "";

    copy(&BEGIN_LANES[0], &BEGIN_LANES[n], back_inserter(lanes));

    initlizeEggs(lanes);
    l.setBaseposition(LASER_CANNON_X, LASER_CANNON_Y);
    l.pointCannonUp();

    window.bombsSpawned = 0;
    window.delayEndFrames = 0;
    window.gameOver = false;
    while(!window.should_close() && !window.gameOver){
        addBombs(window, lanes);
        drawBackground(window);
        drawBombs(window);
        drawEggs(window);
        drawLasers(window);
        l.drawCannon(window);
        explotions.drawExplotions(window);
        drawTypingScreen(window, typeText);
        getCharInput(window, typeText);
        checkIfGameOver(window);

        window.next_frame();
        cout << endl;
    }
    cout << "Spill over" << endl;
}

int bombaddingIterator = 0;
void addBombs(LTWindow& window, vector<int> lanes){
    if(lanes.size() == 0){
        return;
    }

    if (window.bombsSpawned < MAX_NUMBER_OF_BOMBS){
        if (bombaddingIterator == 80){
            window.bombsSpawned++;
            if (window.randInt()%QUOTE_PROBABILITY == 0){
                bombs.emplace_back(std::make_unique<textBomb>(lanes));
                bombaddingIterator = 0;
                return;
            } else{
                bombs.emplace_back(std::make_unique<numBomb>(lanes));
                bombaddingIterator = 0;
                return;
            }
        }
        bombaddingIterator++;
    }
    else{
        if (bombs.size() == 0){
            window.delayEndFrames++;
        }
    }
}

void drawBombs(LTWindow& window){
    /*Her itererer vi over alle blokkelementene. Vi flytter alle et hakk ned 
    og sletter de som har kommet for langt. Her må vi bruke en while-løkke. 
    Mer info: https://www.geeksforgeeks.org/cpp-remove-elements-from-a-list-while-iterating/
    */
    auto it = bombs.begin();
    while (it != bombs.end()){
        (**(it)).moveDown(window);
        if ((*(*it)).get_y() >= getHeightOfeggs() - 100){
            explotions.push_back(Explotion((**it).get_x(), (**it).get_y()));
            damageEggAtXPosition((**it).get_x());
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
        if(guess == (**it).Answer()){
            l.pointCannonAt((**it).get_x(), (**it).get_y());
            explotions.push_back(Explotion((**it).get_x(), (**it).get_y()));
            lasers.push_back(Laser(l, (**it)));
            bombs.erase(it);
            return true;
        }
    }
    return false;
}

void drawLasers(LTWindow& window){
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
    for (auto i = 0; i < lanes.size(); i++){
        if(lanes.at(i) == x){
            lanes.erase(lanes.begin() + i);
            break;
        }
    }

    auto it = bombs.begin();
    while (it != bombs.end()){
        if ((**it).get_x() == x - 50){
            explotions.push_back(Explotion((**it).get_x(), (**it).get_y()));
            eraseEgg((**it).get_x());
            it = bombs.erase(it);
            continue;
        }
        it++;
    }
}

void checkIfGameOver(LTWindow& window){
    if(lanes.size() == 0){
        window.gameOver = true;
        window.currentPageMode = pageMode::frontpage;
        return;
    }
    else if(window.bombsSpawned >= MAX_NUMBER_OF_BOMBS && bombs.size() == 0 && window.delayEndFrames >= 30){
        window.gameOver = true;
        window.currentPageMode = pageMode::frontpage;
        return;
    }
}