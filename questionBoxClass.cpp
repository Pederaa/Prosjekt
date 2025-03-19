#include "QuestionBoxClass.h"
#include "std_lib_facilities.h"
#include "animationWindow.h"
#include <random>

void QuestionBox::moveDown(TDT4102::AnimationWindow& window){
    yPosition += speed;
    drawBoks(window);
}

void QuestionBox::drawBoks(TDT4102::AnimationWindow& window){
    TDT4102::Color writingColor = TDT4102::Color::black;
    TDT4102::Font font = TDT4102::Font::times_bold;
    
    TDT4102::Point position = {xPosition, yPosition};
    TDT4102::Point tmPosition = {xPosition + 83, yPosition};
    string h = "TM";

    window.draw_rectangle(position, width, height, fillColor);
    window.draw_text(position, question, writingColor, 20, font);
    window.draw_text(tmPosition, h, writingColor, 10, font);
}

QuestionBox::QuestionBox(){
    random_device rd;
    default_random_engine generator(rd());
    xPosition = (generator()%7)*200;
    speed = (generator()%5 + 1)*2;

    question = "Hello there";
    answer = "General Kenobi";
}