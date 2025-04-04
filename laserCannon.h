#pragma once
#include "Bomb.h"

class laserCannon{
    TDT4102::Color Color = TDT4102::Color::black;
    int length = LASER_CANNON_LENGTH;

    public:
        TDT4102::Point basePosition;
        TDT4102::Point endPosition;
        laserCannon(int posX, int posY);
        void pointCannonAt(int targetX, int targetY);
        void drawCannon(TDT4102::AnimationWindow& window);
        void setBaseposition(int x, int y);
        int Length();
};


class Laser{
    TDT4102::Point basePosition;
    TDT4102::Point endPosition;
    TDT4102::Color Color = TDT4102::Color::red;
    int frameIndex = 0;
    int maxIndex = LASER_MAXFRAME_INDEX;

    public:
        Laser(laserCannon cannon, Bomb bomb);
        bool drawLaser(TDT4102::AnimationWindow& window);
};