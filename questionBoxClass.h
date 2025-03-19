#pragma once
#include "animationWindow.h"

class QuestionBox{
    int yPosition = 0;
    int xPosition = 0;
    int width = 100;
    int height = 100;
    int speed = 3;

    TDT4102::Color fillColor = TDT4102::Color::light_sea_green;
    std::string question = "Hello there";

    public:
        QuestionBox();
        void moveDown(TDT4102::AnimationWindow& window);
        void drawBoks(TDT4102::AnimationWindow& window);
};