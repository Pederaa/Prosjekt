#pragma once
#include "AnimationWindow.h"
#include "LaserTurtleWindow.h"
#include "quary.h"
#include <random>
#include "constants.h"

class Bomb{
    public:
        int y = BOMB_INITIALY;
        int x;
        int width = BOMB_WIDTH;
        int height = BOMB_HEIGHT;
        int speed = BOMB_SPEED;

        TDT4102::Color fillColor = TDT4102::Color::light_sea_green;
        TDT4102::Color textColor = TDT4102::Color::white;
        TDT4102::Font textFont = TDT4102::Font::times_bold;
        TDT4102::Point topLeftCorner {0, 0};
        TDT4102::Image image = TDT4102::Image("images/bomb2.png");

        Quary quary = Quary("x", "y");
        random_device rd;

        Bomb();
        Bomb(std::vector<int> lanes);
        virtual ~Bomb(){};
        int posX();
        int posY();
        std::string Answer();
        void moveDown(LTWindow& window);
        void drawTekstBoks(LTWindow& window);
};

