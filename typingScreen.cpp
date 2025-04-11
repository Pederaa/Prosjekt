#include "std_lib_facilities.h"
#include "typingScreen.h"
#include "constants.h"

TDT4102::Font font = TDT4102::Font::times_bold;
void drawTypingScreen(LTWindow& window, std::string& c){
    TDT4102::Point pojon = {(WINDOW_WIDTH - TYPINGSCREEN_WIDTH)/2, WINDOW_HEIGH - TYPINGSCREEN_HEIGHT - TYPINGSCREEN_BOTTOMMARGIN};
    window.draw_rectangle(pojon, TYPINGSCREEN_WIDTH, TYPINGSCREEN_HEIGHT, TDT4102::Color::black);
    window.draw_text(pojon, c+"_", TDT4102::Color::white, TYPINGSCREEN_TEXTSIZE, TDT4102::Font::times_bold);
}