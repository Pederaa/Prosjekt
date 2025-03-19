#include "animationWindow.h"
#include "std_lib_facilities.h"
#include "windowManager.h"
#include "QuestionBoxClass.h"
#include <random>

void clicked(){
    cout << "Hei" << std::endl;
}

void drawWindow(){
    TDT4102::AnimationWindow window; //Lager en instanse av et animasjonsvindu.
    
    std::vector<QuestionBox> blocks;
    QuestionBox newBlock = QuestionBox();
    blocks.push_back(newBlock);
    
    default_random_engine generator;
    while(!window.should_close()){
        if (generator()%10 == 1){ // Legger til nye blokker hver 10. frame.  
            newBlock = QuestionBox();
            blocks.push_back(newBlock);
        }
        cout << blocks.size() << endl;

        for(int i=0; i<blocks.size(); i++){
            blocks.at(i).moveDown(window);
        }
        window.next_frame();
    }

    cout << "Vindu lukket" << endl;
}