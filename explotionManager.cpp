#include "explotionManager.h"

Explotion::Explotion(int posX, int posY){
    positionX = posX;
    positionY = posY;

    frame1 =  TDT4102::Image("images/explotion.png");
}

void Explotion::drawExplotion(TDT4102::AnimationWindow& window){
    window.draw_image({positionX, positionY}, frame1, 100, 100);
}