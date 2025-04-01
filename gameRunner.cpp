#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include "gameRunner.h"
#include "Bomb.h"
#include "readKeyInput.h"
#include "backgroundGenerator.h"
#include "typingScreen.h"
#include "eggsManager.h"
#include "laserCannon.h"
#include <bits/stdc++.h>
#include "explotionManager.h"

#include <random>

std::list<Bomb> blocks;
std::list<Explotion> explotions;
std::list<Laser> lasers;
laserCannon l(1,2);

constexpr int WINDOW_WIDTH = 1300; //Bildene skal dimasnjoneres slik at 1 bildepiksel er 2*2 spillpiksler. 
constexpr int WINDOW_HEIGH = 600;
constexpr std::string GAME_NAME = "Laserturtle";
constexpr int BEGIN_LANES[] = {50, 250, 450, 750, 950, 1150};

void runGame(){
    TDT4102::AnimationWindow window(0, 30, WINDOW_WIDTH, WINDOW_HEIGH, GAME_NAME); //Lager en instanse av et animasjonsvindu.
    default_random_engine generator;
    std::string c = "";

    int n = sizeof(BEGIN_LANES);
    int lanes[n];
    copy(BEGIN_LANES, BEGIN_LANES+n, lanes);

    initlizeEggs(lanes);
    l.setPostion(window.width()/2, window.height()-50);
    
    while(!window.should_close()){
        drawBackground(window);
        l.drawCannon(window);
        drawBlocks(window, generator, lanes);
        drawEggs(window);
        drawExplotions(window);
        drawLasers(window);
        drawTypingScreen(window, c);
        getCharInput(window, c);

        window.next_frame();
    }

    cout << "Spill over" << endl;
}

void drawBlocks(TDT4102::AnimationWindow& window, std::default_random_engine& generator, int lanes[]){
    if (generator()%40 == 1){ // Legger til nye blokker ca. hver 40. frame.  
        Bomb newBlock = Bomb(lanes);
        blocks.push_back(newBlock);
    }

    /*Her itererer vi over alle blokkelementene. Vi flytter alle et hakk ned 
    og sletter de som har kommet for langt. Her må vi bruke en while-løkke. 
    Mer info: https://www.geeksforgeeks.org/cpp-remove-elements-from-a-list-while-iterating/
    */
    list<Bomb>::iterator it = blocks.begin();
    while (it != blocks.end()){
        (*it).moveDown(window);
        if ((*it).posY() >= getHeightOfeggs()){
            explotions.push_back(Explotion((*it).posX(), (*it).posY()));
            it = blocks.erase(it);
            continue;
        }
        it++;
    }
}

void checkIfGuessIsCorrect(std::string guess){
    if (blocks.size() == 0){
        return;
    }

    // Her går det fint med en for-løkke siden vi går ut av løkka med en gang den finne ren som passer
    for (auto it = blocks.begin(); it != blocks.end(); it++){
        if(guess == (*it).answerCorrect()){
            l.pointCannonAt(*it);
            explotions.push_back(Explotion((*it).posX(), (*it).posY()));
            lasers.push_back(Laser(l, (*it)));
            blocks.erase(it);
            break;
        }
    }
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