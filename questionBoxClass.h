#pragma once
#include "animationWindow.h"

class QuestionBox{
    public:
        int yPosition = 0;
        int xPosition = 0;
        int width = 100;
        int height = 100;
        int speed = 3;

        TDT4102::Color fillColor = TDT4102::Color::light_sea_green;
        TDT4102::Color textColor = TDT4102::Color::black;
        TDT4102::Font textFont = TDT4102::Font::times_bold;

        std::string question;
        std::string answer;

        QuestionBox();
        void moveDown(TDT4102::AnimationWindow& window);
        void drawBoks(TDT4102::AnimationWindow& window);
};