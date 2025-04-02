#include "eggsManager.h"
#include "AnimationWindow.h"
#include "std_lib_facilities.h"

Egg::Egg(int xPos, int yPos){
    x = xPos;
    y = yPos;
}

void Egg::removeHP(){
    hp -= 1;
}

int Egg::posY(){
    return y;
}

int Egg::posX(){
    return x;
}

void Egg::drawEgg(TDT4102::AnimationWindow& window){
    window.draw_rectangle({x, y}, 10, 20, fillColor);
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
    return eggs.front().posY();
}

void damageEggAtXPosition(int x){
    for (Egg egg : eggs){
        if (egg.posX() == x){
            egg.removeHP();
        }
    }
}