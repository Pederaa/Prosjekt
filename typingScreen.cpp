#include "std_lib_facilities.h"
#include "animationWindow.h"
#include "typingScreen.h"

void drawTypingScreen(TDT4102::AnimationWindow& window, std::string c){
    window.draw_rectangle({400, 400}, 200, 50, TDT4102::Color::black);

    TDT4102::Font font = TDT4102::Font::times_bold;
    window.draw_text({400, 400}, c, TDT4102::Color::white, 20, font);
}