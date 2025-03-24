#include "laserCannon.h"
#include "AnimationWindow.h"
#include <cmath>
#include "std_lib_facilities.h"
#include "questionBoxClass.h"

laserCannon::laserCannon(int posX, int posY){
    basePosition = {posX, posY};
}

void laserCannon::poinCannonAt(int posX, int posY){
    //rotation = acos(length/posX);
    endPosition = {static_cast<int>(std::round(basePosition.x + length/posX)), 
        static_cast<int>(std::round(basePosition.x + length/posY))};
}

void laserCannon::drawCannon(TDT4102::AnimationWindow& window){ 
    window.draw_line(basePosition, endPosition, Color);
    cout << "{" << basePosition.x << ", " << basePosition.y << "}  ->  ";
    cout << "{" << endPosition.x << ", " << endPosition.y << "}" << endl << endl << endl << endl;

}