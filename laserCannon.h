#pragma once
#include "questionBoxClass.h"

class laserCannon{
    TDT4102::Point basePosition;
    TDT4102::Point endPosition;
    TDT4102::Color Color = TDT4102::Color::black;
    int length = 100;

    public:
        laserCannon(int posX, int posY);
        void pointCannonAt(QuestionBox& target);
        void drawCannon(TDT4102::AnimationWindow& window);
        void setPostion(int posX, int posY);
};