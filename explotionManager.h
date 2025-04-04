#pragma once
#include "AnimationWindow.h"
#include "constants.h"

class Explotion{
    int x;
    int y;
    int frameIndex = 0;
    int maxIndex = EXPLOTION_MAXFRAME_INDEX;
    TDT4102::Image frame1 = TDT4102::Image("images/explotion.png");

    public:
        Explotion(int xPos, int yPos);
        bool drawExplotion(TDT4102::AnimationWindow& window);
};