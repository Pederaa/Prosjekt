#include "laserCannon.h"
#include "AnimationWindow.h"
#include <cmath>
#include "std_lib_facilities.h"
#include "Bomb.h"

laserCannon::laserCannon(int posX, int posY){
    basePosition = {posX, posY};
}

void laserCannon::pointCannonAt(Bomb& bomb){
    /*float k = sqrt(pow(length,2)/(pow(bomb.posX() - basePosition.x, 2) + pow(target.posY() - basePosition.y, 2)));

    float tempX;
    if (basePosition.x <= bomb.posX()){
        tempX = basePosition.x + k*(bomb.posX() - basePosition.x);
    } else{
        tempX = basePosition.x - k*(bomb.posX() - basePosition.x);
    }

    float tempY = basePosition.y - k*(basePosition.y - bomb.posY());
    endPosition = {static_cast<int>(std::round(tempX)), static_cast<int>(std::round(tempY))};

    cout << "{" << tempX << ", " << tempY << "}" << endl;
    cout << "{" << endPosition.x << ", " << endPosition.y << ", 100=" << sqrt(pow(endPosition.x - basePosition.x, 2) + pow(endPosition.y - endPosition.y, 2)) << "}" << endl << endl << endl << endl;
    */
    
    if (basePosition.x <= bomb.posX()){
        endPosition.x = basePosition.x + length/(sqrt(1 + pow((bomb.posX() - basePosition.x)/(bomb.posY() - basePosition.y), 2)));
    }
    else{
        endPosition.x = basePosition.x - length/(sqrt(1 + pow((bomb.posX() - basePosition.x)/(bomb.posY() - basePosition.y), 2)));
    }
    endPosition.y = basePosition.y - length/(sqrt(1 + pow((bomb.posY() - basePosition.y)/(bomb.posX() - basePosition.x), 2)));
    
    //cout << "{" << bomb.posX() << ", " << bomb.posY() << "}" << endl;
    //cout << "{" << endPosition.x << ", " << endPosition.y << ", 100=" << sqrt(pow(endPosition.x - basePosition.x, 2) + pow(endPosition.y - basePosition.y, 2)) << "}" << endl << endl << endl << endl;
}

void laserCannon::drawCannon(TDT4102::AnimationWindow& window){ 
    window.draw_line(basePosition, endPosition, Color);
}

void laserCannon::setBaseposition(int x, int y){
    basePosition = {x, y};
}

Laser::Laser(laserCannon cannon, Bomb bomb){
    basePosition = cannon.basePosition;
    endPosition = {bomb.posX()+50, bomb.posY()+50};
}

bool Laser::drawLaser(TDT4102::AnimationWindow& window){
    if (frameIndex >= maxIndex){
        return true;
    }

    window.draw_line(basePosition, endPosition, Color);
    frameIndex++;
    return false;
}