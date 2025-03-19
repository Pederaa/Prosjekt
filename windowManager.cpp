#include "animationWindow.h"
#include "std_lib_facilities.h"
#include "windowManager.h"
#include "QuestionBoxClass.h"
#include "readKeyInput.h"
#include "backgroundGenerator.h"
#include "typingScreen.h"

#include <random>

void beginGame(){
    TDT4102::AnimationWindow window; //Lager en instanse av et animasjonsvindu.
    std::string c = "";
        
    while(!window.should_close()){
        drawBackground(window);
        drawBlocks(window);
    
        getCharInput(window, c);
        drawTypingScreen(window, c);

        window.next_frame();
    }

    cout << "Vindu lukket" << endl;
}

void drawBlocks(TDT4102::AnimationWindow window){
    static std::vector<QuestionBox> blocks;
    default_random_engine generator;

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