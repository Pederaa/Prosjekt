#include "Bomb.h"
#include "std_lib_facilities.h"
#include <random>
#include "animationWindow.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <quary.h>

int Bomb::posY(){
    return this->yPosition;
}

int Bomb::posX(){
    return this->xPosition;
}

std::string Bomb::Answer(){
    return question.answer;
}

void Bomb::moveDown(TDT4102::AnimationWindow& window){
    yPosition += speed;
    drawTekstBoks(window);
}

void Bomb::drawTekstBoks(TDT4102::AnimationWindow& window){
    window.draw_image({xPosition, yPosition}, image, 100, 100);
    window.draw_text({xPosition+30, yPosition+40}, question.question, textColor, 20, textFont);
}

Bomb::Bomb(std::vector<int> lanes){
    random_device rd;
    default_random_engine generator(rd());
    xPosition = lanes[(generator()%(lanes.size()))] - width/2;
    speed = (generator()%2 + 2 );
    image = TDT4102::Image("images/bomb2.png"); 
}