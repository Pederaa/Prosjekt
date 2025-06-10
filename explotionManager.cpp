#include "explotionManager.h"
#include "std_lib_facilities.h"
#include "LaserTurtleWindow.h"
#include "AnimationWindow.h"

Explotion::Explotion(int posX, int posY){
    x = posX-20;
    y = posY-10;
}

bool Explotion::drawExplotion(TDT4102::AnimationWindow& window){
    if (frameIndex >= maxIndex){
        return true;
    }

    if (frameIndex <= 2){
        window.draw_image({x, y}, frame4, EXPLOTION_WIDTH, EXPLOTION_HEIGHT);
    }
    else if (frameIndex <= 4){
        window.draw_image({x, y}, frame4, EXPLOTION_WIDTH, EXPLOTION_HEIGHT);
    }
    else if (frameIndex <= 6){
        window.draw_image({x, y}, frame5, EXPLOTION_WIDTH, EXPLOTION_HEIGHT);
    }
    else if (frameIndex <= 8){
        window.draw_image({x, y}, frame5, EXPLOTION_WIDTH, EXPLOTION_HEIGHT);
    }
    else if (frameIndex <= 10){
        window.draw_image({x, y}, frame6, EXPLOTION_WIDTH, EXPLOTION_HEIGHT);
    }
    else if (frameIndex <= 12){
        window.draw_image({x, y}, frame6, EXPLOTION_WIDTH, EXPLOTION_HEIGHT);
    }
    else {
        window.draw_image({x, y}, frame7, EXPLOTION_WIDTH, EXPLOTION_HEIGHT);
    }

    frameIndex++;
    return false;
}

void Explotions::drawExplotions(LTWindow& window){
    auto it = this->begin();
    while (it != this->end()){
        bool isExplotionDone = (*it).drawExplotion(window);

        if (isExplotionDone){
            it = this->erase(it);
            continue;
        }
        it++;
    }
}