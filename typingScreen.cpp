#include "std_lib_facilities.h"
#include "animationWindow.h"
#include "typingScreen.h"
#include "constants.h"

TDT4102::Font font = TDT4102::Font::times_bold;
void drawTypingScreen(TDT4102::AnimationWindow& window, std::string c){
    TDT4102::Point posisjon = {(window.width() - TYPINGSCREEN_WIDTH)/2, window.height() - TYPINGSCREEN_HEIGHT - TYPINGSCREEN_BOTTOMMARGIN};

    window.draw_rectangle(posisjon, TYPINGSCREEN_WIDTH, TYPINGSCREEN_HEIGHT, TDT4102::Color::black);

    window.draw_text(posisjon, c, TDT4102::Color::white, TYPINGSCREEN_TEXTSIZE, font);
}