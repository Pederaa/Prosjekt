#include "QuestionBoxClass.h"
#include "std_lib_facilities.h"
#include "animationWindow.h"
#include <random>

void QuestionBox::moveDown(TDT4102::AnimationWindow& window){
    yPosition += speed;
    drawBoks(window);
}

void QuestionBox::drawBoks(TDT4102::AnimationWindow& window){
    window.draw_rectangle({xPosition, yPosition}, width, height, fillColor);
    window.draw_text({xPosition, yPosition}, question, textColor, 20, textFont);
    window.draw_text({xPosition + 83, yPosition}, "TM", textColor, 10, textFont);
}

QuestionBox::QuestionBox(){
    random_device rd;
    default_random_engine generator(rd());
    xPosition = (generator()%7)*200;
    speed = (generator()%5 + 1)*2;

    question = "Hello there";
    answer = "General Kenobi";
}