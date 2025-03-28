#include "Egg.h"
#include "AnimationWindow.h"

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