#include "Bomb.h"
#include "std_lib_facilities.h"
#include <random>
#include "animationWindow.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <quary.h>

int Bomb::posY(){
    return this->y;
}

int Bomb::posX(){
    return this->x;
}

std::string Bomb::Answer(){
    return quary.answer;
}

void Bomb::moveDown(TDT4102::AnimationWindow& window){
    y += speed;
    drawTekstBoks(window);
}

void Bomb::drawTekstBoks(TDT4102::AnimationWindow& window){
    window.draw_image({x, y}, image, width, height);
    window.draw_text({x+30, y+40}, quary.question, textColor, 20, textFont);
}

Bomb::Bomb(){
    //generator = generator(rd);
    image = TDT4102::Image("images/bomb2.png"); 
}