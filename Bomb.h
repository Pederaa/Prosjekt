#pragma once
#include "AnimationWindow.h"
#include "quary.h"

class Bomb{
    public:
        int yPosition = 0;
        int xPosition = 0;
        int width = 100;
        int height = 100;
        int speed = 3;

        TDT4102::Color fillColor = TDT4102::Color::light_sea_green;
        TDT4102::Color textColor = TDT4102::Color::white;
        TDT4102::Font textFont = TDT4102::Font::times_bold;
        TDT4102::Point topLeftCorner {0, 0};
        TDT4102::Image image;

        Quary question;

        Bomb();
        Bomb(std::vector<int> lanes);
        int posX();
        int posY();
        std::string Answer();
        void moveDown(TDT4102::AnimationWindow& window);
        void drawTekstBoks(TDT4102::AnimationWindow& window);
};

