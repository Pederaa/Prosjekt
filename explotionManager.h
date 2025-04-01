#pragma once
#include "AnimationWindow.h"

class ExplotionList{

};

class Explotion{
    int positionX;
    int positionY;
    TDT4102::Image frame1;

    public:
        Explotion(int xPos, int yPos);
        void drawExplotion(TDT4102::AnimationWindow& window);

};