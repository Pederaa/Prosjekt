#include "laserCannon.h"
#include "AnimationWindow.h"
#include <cmath>
#include "std_lib_facilities.h"
#include "Bomb.h"

laserCannon::laserCannon(int posX, int posY){
    basePosition = {posX, posY};
}

void laserCannon::pointCannonAt(int targetX, int targetY){
    try{
        endPosition.x = basePosition.x - length*((basePosition.x - targetX-BOMB_CENTERCORRECTION_X))/sqrt(pow(basePosition.x - targetX-BOMB_CENTERCORRECTION_X, 2) + pow(basePosition.y - targetY-BOMB_CENTERCORRECTION_Y, 2));
        endPosition.y = basePosition.y - length*((basePosition.y - targetY-BOMB_CENTERCORRECTION_Y))/sqrt(pow(basePosition.x - targetX-BOMB_CENTERCORRECTION_X, 2) + pow(basePosition.y - targetY-BOMB_CENTERCORRECTION_Y, 2));    
    }
    catch(int x) {
        this->pointCannonUp();
        return;
    }

    rotation = std::atan2(basePosition.y - endPosition.y, endPosition.x - basePosition.x);
}

void laserCannon::pointCannonUp(){
    endPosition.x = basePosition.x;
    endPosition.y = basePosition.y-length;
    rotation = 3.14/2;
}

static TDT4102::Image turtle_left_png = TDT4102::Image("images/turtle_left.png");
static TDT4102::Image turtle_right_png = TDT4102::Image("images/turtle_right.png");
void laserCannon::drawCannon(TDT4102::AnimationWindow& window){ 
    window.draw_quad(
        {basePosition.x - (int)((widht/2)*sin(rotation)), basePosition.y - (int)((widht/2)*cos(rotation))},
        {basePosition.x + (int)((widht/2)*sin(rotation)), basePosition.y + (int)((widht/2)*cos(rotation))},
        {endPosition.x + (int)((widht/2)*sin(rotation)), endPosition.y + (int)((widht/2)*cos(rotation))},
        {endPosition.x - (int)((widht/2)*sin(rotation)), endPosition.y - (int)((widht/2)*cos(rotation))},
        Color);
    
    if (cos(rotation) >= 0){
        window.draw_image({basePosition.x + TURTLE_XOFFSET + 15, basePosition.y + TURTLE_YOFFSET}, 
            turtle_right_png, TURTLE_SIZE, TURTLE_SIZE);
    }
    else{
        window.draw_image({basePosition.x + TURTLE_XOFFSET, basePosition.y + TURTLE_YOFFSET}, 
            turtle_left_png, TURTLE_SIZE, TURTLE_SIZE);
    }
}

void laserCannon::setBaseposition(int x, int y){
    basePosition = {x, y};
}

TDT4102::Point laserCannon::getBasePosition(){
    return basePosition;
}


int laserCannon::Length(){
    return length;
}

Laser::Laser(laserCannon cannon, Bomb bomb){
    basePosition = cannon.basePosition;
    endPosition = {bomb.posX()+BOMB_CENTERCORRECTION_X, bomb.posY()+BOMB_CENTERCORRECTION_Y};
    rotation = std::atan2(basePosition.y - endPosition.y, endPosition.x - basePosition.x);
}

bool Laser::drawLaser(TDT4102::AnimationWindow& window){
    if (frameIndex >= maxIndex){
        return true;
    }

    window.draw_quad(
        {basePosition.x - (int)((widht/2)*sin(rotation)), basePosition.y - (int)((widht/2)*cos(rotation))},
        {basePosition.x + (int)((widht/2)*sin(rotation)), basePosition.y + (int)((widht/2)*cos(rotation))},
        {endPosition.x + (int)((widht/2)*sin(rotation)), endPosition.y + (int)((widht/2)*cos(rotation))},
        {endPosition.x - (int)((widht/2)*sin(rotation)), endPosition.y - (int)((widht/2)*cos(rotation))},
        Color);

    frameIndex++;
    return false;
}

void drawTurtle(TDT4102::AnimationWindow& window){

}