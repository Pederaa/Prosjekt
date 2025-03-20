#include "Egg.h"
#include "AnimationWindow.h"

Egg::Egg(int xPos){
    positionX = xPos;
}

void Egg::removeHP(){
    hp -= 1;

}

void Egg::drawEgg(TDT4102::AnimationWindow& window){
    window.draw_rectangle({positionX, positionY}, 10, 20, fillColor);
}