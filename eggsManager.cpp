#include "eggsManager.h"
#include "AnimationWindow.h"
#include "std_lib_facilities.h"

Egg::Egg(int xPos, int yPos){
    x = xPos;
    y = yPos;

    hp = 3;
}

void Egg::removeHP(){
    hp--;
}

int Egg::posY(){
    return y;
}

int Egg::posX(){
    return x;
}

void Egg::drawEgg(TDT4102::AnimationWindow& window){
    switch(hp){
        case 3:
            window.draw_rectangle({x-10-5, y}, 10, 20, fillColor);
            window.draw_rectangle({x, y}, 10, 20, fillColor);
            window.draw_rectangle({x+10+5, y}, 10, 20, fillColor);
            break;

        case 2:
            window.draw_rectangle({x-10-2, y}, 10, 20, fillColor);
            window.draw_rectangle({x+3, y}, 10, 20, fillColor);
            break;

        case 1:
            window.draw_rectangle({x, y}, 10, 20, fillColor);
            break;

        case 0:
            break;
    }
}


static std::vector<Egg> eggs;
void initlizeEggs(int lanes[]){
    for (int i=0; i<sizeof(lanes); i++) {
        eggs.push_back(Egg(lanes[i], 500));
    }
}

void drawEggs(TDT4102::AnimationWindow& window){

    auto it = eggs.begin();
    while (it != eggs.end()){
        (*it).drawEgg(window);
        it++;
    }
}

int getHeightOfeggs(){
    return eggs.front().posY();
}

void damageEggAtXPosition(int x){
    auto it = eggs.begin();
    while (it != eggs.end()){
        if ((*it).posX() == x + 50){
            (*it).removeHP();
            break;
        }
        it++;
    }
}