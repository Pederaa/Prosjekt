#include "explotionManager.h"
#include "std_lib_facilities.h"

Explotion::Explotion(int posX, int posY){
    x = posX;
    y = posY;
}

bool Explotion::drawExplotion(TDT4102::AnimationWindow& window){
    if (frameIndex >= maxIndex){
        return true;
    }

    window.draw_image({x, y}, frame1, EXPLOTION_WIDTH, EXPLOTION_HEIGHT);
    frameIndex++;
    return false;
}