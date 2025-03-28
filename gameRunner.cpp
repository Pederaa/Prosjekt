#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include "gameRunner.h"
#include "questionBoxClass.h"
#include "readKeyInput.h"
#include "backgroundGenerator.h"
#include "typingScreen.h"
#include "eggsManager.h"
#include "laserCannon.h"
#include <bits/stdc++.h>

#include <random>

std::list<QuestionBox> blocks;
laserCannon l(1,2);

void runGame(){
    TDT4102::AnimationWindow window(0, 0, 1000, 500, "Laserturtle"); //Lager en instanse av et animasjonsvindu.
    default_random_engine generator;
    std::string c = "";

    int lanes[] = {50, 250, 450, 750, 950, 1150};
    initlizeEggs(lanes);
    l.setPostion(window.width()/2, window.height()-300);
    
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
        QuestionBox newBlock = QuestionBox(lanes);
        blocks.push_back(newBlock);
    }

    /*Her itererer vi over alle blokkelementene. Vi flytter alle et hakk ned 
    og sletter de som har kommet for langt. Her må vi bruke en while-løkke. 
    Mer info: https://www.geeksforgeeks.org/cpp-remove-elements-from-a-list-while-iterating/
    */
    list<QuestionBox>::iterator it = blocks.begin();
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
        else{
            //std::cout << ": False" << endl;;
        }
    }
}