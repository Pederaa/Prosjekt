#include "QuestionBoxClass.h"
#include "std_lib_facilities.h"
#include <random>
#include "animationWindow.h"
#include <algorithm>
#include <cctype>
#include <string>

int QuestionBox::posY(){
    return this->xPosition;
}

int QuestionBox::posX(){
    return this->xPosition;
}

bool QuestionBox::answerCorrect(std::string guess){
    return guess == answer;
}

void QuestionBox::moveDown(TDT4102::AnimationWindow& window){
    yPosition += speed;
    drawBoks(window);
}

void QuestionBox::drawBoks(TDT4102::AnimationWindow& window){
    window.draw_rectangle({xPosition, yPosition}, width, height, fillColor);
    window.draw_text({xPosition, yPosition}, question, textColor, 20, textFont);
    window.draw_text({xPosition + 83, yPosition}, "TM", textColor, 10, textFont);
}

void QuestionBox::deleteBlock(){
    // SKal slette blokk
}

QuestionBox::QuestionBox(int lanes[]){
    random_device rd;
    default_random_engine generator(rd());
    xPosition = lanes[(generator()%sizeof(lanes))] - width/2;
    speed = (generator()%5 + 1 );

    question = "Hello there";
    answer = "AA";
}
