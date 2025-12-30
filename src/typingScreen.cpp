#include "std_lib_facilities.h"
#include "typingScreen.h"
#include "constants.h"

TDT4102::Font font = TDT4102::Font::times_bold;
void drawTypingScreen(LTWindow& window, std::string& c){
    TDT4102::Point pojon = {(WINDOW_WIDTH - TYPINGSCREEN_WIDTH)/2, WINDOW_HEIGH - TYPINGSCREEN_HEIGHT - TYPINGSCREEN_BOTTOMMARGIN};
    window.draw_rectangle(pojon, TYPINGSCREEN_WIDTH, TYPINGSCREEN_HEIGHT, TDT4102::Color::black);
    

    int TYPINGSCREEN_MAXLENGTH = 13;
    if (c.length() <= TYPINGSCREEN_MAXLENGTH){
        window.draw_text(pojon, c+"_", TDT4102::Color::white, TYPINGSCREEN_TEXTSIZE, TDT4102::Font::times_bold);
        return;
    }
    else if (c.length() <= 2*TYPINGSCREEN_MAXLENGTH){
        int numOfSpaces = std::ranges::count(c, ' ') + 1;

        vector<std::string> g;
        g.push_back(c.substr(0, TYPINGSCREEN_MAXLENGTH)+"-");
        g.push_back(c.substr(TYPINGSCREEN_MAXLENGTH, c.length()-TYPINGSCREEN_MAXLENGTH)+"_");
    
        window.draw_text(pojon, g.at(0), TDT4102::Color::white, TYPINGSCREEN_TEXTSIZE, TDT4102::Font::times_bold);
        window.draw_text({pojon.x, pojon.y + 14}, g.at(1), TDT4102::Color::white, TYPINGSCREEN_TEXTSIZE, TDT4102::Font::times_bold);
    }
    else{
        c.pop_back();
    }
}