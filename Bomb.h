#pragma once
#include "AnimationWindow.h"
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
        TDT4102::Image image;

        Quary quary;

        Bomb();
        Bomb(std::vector<int> lanes);
        int posX();
        int posY();
        std::string Answer();
        void moveDown(TDT4102::AnimationWindow& window);
        void drawTekstBoks(TDT4102::AnimationWindow& window);
};

