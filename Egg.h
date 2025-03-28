#pragma once
#include "AnimationWindow.h"

class Egg{
    int hp = 3;
    int positionY = 0;
    int positionX = 0;
    TDT4102::Color fillColor = TDT4102::Color::red;

    public:
        Egg();
        Egg(int xPos, int yPos);
        void removeHP();
        int y();
        void drawEgg(TDT4102::AnimationWindow& window);
};