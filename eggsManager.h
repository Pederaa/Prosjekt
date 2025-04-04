#pragma once
#include "AnimationWindow.h"
#include "constants.h"

class Egg{
    int y = EGGS_Y;
    int x = 0;
    TDT4102::Color fillColor = TDT4102::Color::red;

    public:
        int hp = EGGS_MAXHP;
        Egg();
        Egg(int xPos);
        void removeHP();
        int posY();
        int posX();
        void drawEgg(TDT4102::AnimationWindow& window);
};

void initlizeEggs(std::vector<int> lanes);
void drawEggs(TDT4102::AnimationWindow& window);
int getHeightOfeggs();
void damageEggAtXPosition(int x);
void eraseEgg(int x);