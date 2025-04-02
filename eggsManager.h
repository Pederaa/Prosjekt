#pragma once
#include "AnimationWindow.h"

class Egg{
    int hp = 3;
    int y = 0;
    int x = 0;
    TDT4102::Color fillColor = TDT4102::Color::red;

    public:
        Egg();
        Egg(int xPos, int yPos);
        void removeHP();
        int posY();
        int posX();
        void drawEgg(TDT4102::AnimationWindow& window);
};


void initlizeEggs(int lanes[]);
void drawEggs(TDT4102::AnimationWindow& window);
int getHeightOfeggs();
void damageEggAtXPosition(int x);
