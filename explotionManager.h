#pragma once
#include "AnimationWindow.h"

class ExplotionList{

};

class Explotion{
    int positionX;
    int positionY;
    int frameIndex = 0;
    int maxIndex = 15;
    TDT4102::Image frame1 = TDT4102::Image("images/explotion.png");

    public:
        Explotion(int xPos, int yPos);
        bool drawExplotion(TDT4102::AnimationWindow& window);
};