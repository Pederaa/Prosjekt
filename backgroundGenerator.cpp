#include "backgroundGenerator.h"
#include "animationwindow.h"

void drawBackground(TDT4102::AnimationWindow& window){
    TDT4102::Color grassColor = TDT4102::Color::green;

    window.draw_rectangle({0, window.height()-100}, window.width(), 100, grassColor);
}