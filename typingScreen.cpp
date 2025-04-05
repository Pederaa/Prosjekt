#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "typingScreen.h"
#include "constants.h"

TDT4102::Font font = TDT4102::Font::times_bold;
void drawTypingScreen(TDT4102::AnimationWindow& window, std::string& c){
    //cout << "\t g" << endl;
    TDT4102::Point pojon = {(WINDOW_WIDTH - TYPINGSCREEN_WIDTH)/2, WINDOW_HEIGH - TYPINGSCREEN_HEIGHT - TYPINGSCREEN_BOTTOMMARGIN};
    //cout << "\t j" << endl;
    window.draw_rectangle(pojon, TYPINGSCREEN_WIDTH, TYPINGSCREEN_HEIGHT, TDT4102::Color::black);
    //cout << "\t l" << endl;
    window.draw_text(pojon, c, TDT4102::Color::white, TYPINGSCREEN_TEXTSIZE, TDT4102::Font::times_bold);
    //cout << "\t n" << endl;

}