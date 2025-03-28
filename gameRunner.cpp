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

#include <random>

std::list<Bomb> blocks;
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

    std::cout << std::endl;
    std::cout << std::endl;

    for (auto it = blocks.begin(); it != blocks.end(); it++){
        if(guess == (*it).answerCorrect()){
            l.pointCannonAt(*it);
            blocks.erase(it);
            break;
        }
    }
}