#include "laserCannon.h"
#include "AnimationWindow.h"
#include <cmath>
#include "std_lib_facilities.h"
#include "questionBoxClass.h"

laserCannon::laserCannon(int posX, int posY){
    basePosition = {posX, posY};
}

void laserCannon::pointCannonAt(QuestionBox& target){
    /*float k = sqrt(pow(length,2)/(pow(target.posX() - basePosition.x, 2) + pow(target.posY() - basePosition.y, 2)));

    float tempX;
    if (basePosition.x <= target.posX()){
        tempX = basePosition.x + k*(target.posX() - basePosition.x);
    } else{
        tempX = basePosition.x - k*(target.posX() - basePosition.x);
    }

    float tempY = basePosition.y - k*(basePosition.y - target.posY());
    endPosition = {static_cast<int>(std::round(tempX)), static_cast<int>(std::round(tempY))};

    cout << "{" << tempX << ", " << tempY << "}" << endl;
    cout << "{" << endPosition.x << ", " << endPosition.y << ", 100=" << sqrt(pow(endPosition.x - basePosition.x, 2) + pow(endPosition.y - endPosition.y, 2)) << "}" << endl << endl << endl << endl;
    */
    
    if (basePosition.x <= target.posX()){
        endPosition.x = basePosition.x + length/(sqrt(1 + pow((target.posX() - basePosition.x)/(target.posY() - basePosition.y), 2)));
    }
    else{
        endPosition.x = basePosition.x - length/(sqrt(1 + pow((target.posX() - basePosition.x)/(target.posY() - basePosition.y), 2)));
    }
    endPosition.y = basePosition.y - length/(sqrt(1 + pow((target.posY() - basePosition.y)/(target.posX() - basePosition.x), 2)));
    
    cout << "{" << target.posX() << ", " << target.posY() << "}" << endl;
    cout << "{" << endPosition.x << ", " << endPosition.y << ", 100=" << sqrt(pow(endPosition.x - basePosition.x, 2) + pow(endPosition.y - basePosition.y, 2)) << "}" << endl << endl << endl << endl;
}

void laserCannon::drawCannon(TDT4102::AnimationWindow& window){ 
    window.draw_line(basePosition, endPosition, Color);
}

void laserCannon::setPostion(int posX, int posY){
    basePosition = {posX, posY};
}