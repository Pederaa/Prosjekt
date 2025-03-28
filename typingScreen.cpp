#include "std_lib_facilities.h"
#include "animationWindow.h"
#include "typingScreen.h"

void drawTypingScreen(TDT4102::AnimationWindow& window, std::string c){
    TDT4102::Point posisjon = {window.width()/2 - 100, window.height() - 20};

    window.draw_rectangle(posisjon, 200, 50, TDT4102::Color::black);

    TDT4102::Font font = TDT4102::Font::times_bold;
    window.draw_text(posisjon, c, TDT4102::Color::white, 20, font);
}