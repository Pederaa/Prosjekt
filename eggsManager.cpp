#include "eggsManager.h"
#include "AnimationWindow.h"
#include "std_lib_facilities.h"

Egg::Egg(int xPos, int yPos){
    positionX = xPos;
    positionY = yPos;
}

void Egg::removeHP(){
    hp -= 1;
}

int Egg::y(){
    return positionY;
}

void Egg::drawEgg(TDT4102::AnimationWindow& window){
    window.draw_rectangle({positionX, positionY}, 10, 20, fillColor);
}


static std::vector<Egg> eggs;
void initlizeEggs(int lanes[]){
    for (int i=0; i<sizeof(lanes); i++) {
        eggs.push_back(Egg(lanes[i], 500));
    }
}

void drawEggs(TDT4102::AnimationWindow& window){
    for (Egg egg : eggs){
        egg.drawEgg(window);
    }
}

int getHeightOfeggs(){
    return eggs.front().y();
}