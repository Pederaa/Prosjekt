#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include "windowManager.h"
#include "questionBoxClass.h"
#include "readKeyInput.h"
#include "backgroundGenerator.h"
#include "typingScreen.h"

#include <random>
std::vector<QuestionBox> blocks;

void runGame(){
    TDT4102::AnimationWindow window; //Lager en instanse av et animasjonsvindu.
    default_random_engine generator;
    std::string c = "";
        
    while(!window.should_close()){
        drawBackground(window);
        drawBlocks(window, generator);
    
        getCharInput(window, c);
        drawTypingScreen(window, c);

        window.next_frame();
    }

    cout << "Spill over" << endl;
}

void drawBlocks(TDT4102::AnimationWindow& window, default_random_engine& generator){
    if (generator()%10 == 1){ // Legger til nye blokker ca. hver 10. frame.  
        QuestionBox newBlock = QuestionBox();
        blocks.push_back(newBlock);
    }

    for(int i=0; i<blocks.size(); i++){
        blocks.at(i).moveDown(window);
    }

    if (!blocks.empty()){
        if (blocks.at(0).yPosition > 500){
            blocks.erase(blocks.begin());
        }
    }
}