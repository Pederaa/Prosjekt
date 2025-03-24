#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include "gameRunner.h"
#include "questionBoxClass.h"
#include "readKeyInput.h"
#include "backgroundGenerator.h"
#include "typingScreen.h"
#include "eggsManager.h"
#include "laserCannon.h"

#include <random>
std::vector<QuestionBox> blocks;

void runGame(){
    TDT4102::AnimationWindow window; //Lager en instanse av et animasjonsvindu.
    default_random_engine generator;
    std::string c = "";

    int lanes[] = {50, 250, 450, 750, 950, 1150};
    initlizeEggs(lanes);
    laserCannon l(window.width()/2, window.height()-300);
    l.poinCannonAt(window.width()/2, 1);
    
    while(!window.should_close()){
        l.drawCannon(window);
        getCharInput(window, c);
        drawBackground(window);
        getCharInput(window, c);
        drawBlocks(window, generator, lanes);
        getCharInput(window, c);
        drawEggs(window);
        getCharInput(window, c);
        drawTypingScreen(window, c);
        getCharInput(window, c);
        window.next_frame();
    }

    cout << "Spill over" << endl;
}

void drawBlocks(TDT4102::AnimationWindow& window, std::default_random_engine& generator, int lanes[]){
    if (generator()%40 == 1){ // Legger til nye blokker ca. hver 10. frame.  
        QuestionBox newBlock = QuestionBox(lanes);
        blocks.push_back(newBlock);
    }

    for(int i=0; i<blocks.size(); i++){
        blocks.at(i).moveDown(window);
    }

    if (!blocks.empty()){
        if (blocks.at(0).posY() > 500){
            blocks.erase(blocks.begin());
        }
    }
}

void checkIfGuessIsCorrect(std::string guess){
    if (blocks.size() == 0){
        return;
    }

    for (int i=0; i<blocks.size(); i++){
        if(blocks[i].answerCorrect(guess)){
            blocks.erase(blocks.begin() + i);
            return;
        }
    }
}