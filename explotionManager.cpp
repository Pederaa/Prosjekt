#include "explotionManager.h"
#include "std_lib_facilities.h"

Explotion::Explotion(int posX, int posY){
    positionX = posX;
    positionY = posY;
}

bool Explotion::drawExplotion(TDT4102::AnimationWindow& window){
    if (frameIndex >= maxIndex){
        return true;
    }

    window.draw_image({positionX, positionY}, frame1, 100, 100);
    frameIndex++;
    return false;
}