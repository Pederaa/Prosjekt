#include "laserCannon.h"
#include "AnimationWindow.h"
#include <cmath>
#include "std_lib_facilities.h"
#include "questionBoxClass.h"

laserCannon::laserCannon(int posX, int posY){
    basePosition = {posX, posY};
}

void laserCannon::pointCannonAt(int posX, int posY){
    float l = sqrt(pow(length,2)/(pow(posX, 2) + pow(posY, 2)));

    float tempX = basePosition.x + l*posX;
    float tempY = basePosition.y + l*posY;
    endPosition = {static_cast<int>(std::round(tempX)), static_cast<int>(std::round(tempY))};

    cout << "{" << tempX << ", " << tempY << "}" << endl;
    cout << "{" << endPosition.x << ", " << endPosition.y << "}" << endl << endl << endl << endl;
}

void laserCannon::drawCannon(TDT4102::AnimationWindow& window){ 
    window.draw_line(basePosition, endPosition, Color);
}

void laserCannon::setPostion(int posX, int posY){
    basePosition = {posX, posY};
}