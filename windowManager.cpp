#include "animationWindow.h"
#include "std_lib_facilities.h"
#include "windowManager.h"
#include "QuestionBoxClass.h"
#include "readKeyInput.h"
#include "backgroundGenerator.h"

#include <random>

void drawWindow(){
    TDT4102::AnimationWindow window; //Lager en instanse av et animasjonsvindu.
    
    static std::vector<QuestionBox> blocks;
    QuestionBox newBlock = QuestionBox();
    blocks.push_back(newBlock);
    std::string c = "";
    
    default_random_engine generator;
    while(!window.should_close()){
        drawBackground(window);

        if (generator()%10 == 1){ // Legger til nye blokker ca. hver 10. frame.  
            newBlock = QuestionBox();
            blocks.push_back(newBlock);
        }
        cout << blocks.size() << endl;

        for(int i=0; i<blocks.size(); i++){
            blocks.at(i).moveDown(window);
        }

        if (!blocks.empty()){
            if (blocks.at(0).yPosition > 500){
                blocks.erase(blocks.begin());
            }
        }
    
        getCharInput(window, c);
        window.next_frame();
    }

    cout << "Vindu lukket" << endl;
}