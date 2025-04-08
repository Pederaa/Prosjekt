#pragma once
#include "Bomb.h"

class laserCannon{
    TDT4102::Color Color = TDT4102::Color::gray;
    int length = LASER_CANNON_LENGTH;

    public:
        TDT4102::Point basePosition;
        TDT4102::Point endPosition;
        double rotation = 0;
        int widht = 10;
        laserCannon(int posX, int posY);
        void pointCannonAt(int targetX, int targetY);
        void pointCannonUp();
        void drawCannon(TDT4102::AnimationWindow& window);
        void setBaseposition(int x, int y);
        TDT4102::Point getBasePosition();
        int Length();
};


class Laser{
    TDT4102::Point basePosition;
    TDT4102::Point endPosition;
    TDT4102::Color Color = TDT4102::Color::red;
    int widht = 5;
    double rotation = 0;
    int frameIndex = 0;
    int maxIndex = LASER_MAXFRAME_INDEX;

    public:
        Laser(laserCannon cannon, Bomb bomb);
        bool drawLaser(TDT4102::AnimationWindow& window);
};