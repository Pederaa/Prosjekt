#pragma once
#include "AnimationWindow.h"

class ExplotionList{

};

class Explotion{
    int positionX;
    int positionY;
    int frameIndex;
    int maxIndex = 10;
    TDT4102::Image frame1;

    public:
        Explotion(int xPos, int yPos);
        bool drawExplotion(TDT4102::AnimationWindow& window);

};