#include "laserCannon.h"
#include "AnimationWindow.h"
#include <cmath>
#include "std_lib_facilities.h"
#include "Bomb.h"

laserCannon::laserCannon(int posX, int posY){
    basePosition = {posX, posY};
}

void laserCannon::pointCannonAt(int targetX, int targetY){
    endPosition.x = basePosition.x - length*((basePosition.x - targetX-BOMB_CENTERCORRECTION_X))/sqrt(pow(basePosition.x - targetX-BOMB_CENTERCORRECTION_X, 2) + pow(basePosition.y - targetY-BOMB_CENTERCORRECTION_Y, 2));
    endPosition.y = basePosition.y - length*((basePosition.y - targetY-BOMB_CENTERCORRECTION_Y))/sqrt(pow(basePosition.x - targetX-BOMB_CENTERCORRECTION_X, 2) + pow(basePosition.y - targetY-BOMB_CENTERCORRECTION_Y, 2));
}

void laserCannon::drawCannon(TDT4102::AnimationWindow& window){ 
    window.draw_line(basePosition, endPosition, Color);
}

void laserCannon::setBaseposition(int x, int y){
    basePosition = {x, y};
}

int laserCannon::Length(){
    return length;
}

Laser::Laser(laserCannon cannon, Bomb bomb){
    basePosition = cannon.basePosition;
    endPosition = {bomb.posX()+BOMB_CENTERCORRECTION_X, bomb.posY()+BOMB_CENTERCORRECTION_Y};
}

bool Laser::drawLaser(TDT4102::AnimationWindow& window){
    if (frameIndex >= maxIndex){
        return true;
    }

    window.draw_line(basePosition, endPosition, Color);
    frameIndex++;
    return false;
}