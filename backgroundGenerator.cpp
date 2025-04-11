#include "LaserTurtleWindow.h"
#include "AnimationWindow.h"
#include "backgroundGenerator.h"

TDT4102::Image image("images/newbackgraund.png");
void drawBackground(LTWindow& window){
    //TDT4102::Color grassColor = TDT4102::Color::green;
    //window.draw_rectangle({0, window.height()-100}, window.width(), 100, grassColor);

    TDT4102::Point topLeftCorner {0, 0};
    window.draw_image(topLeftCorner, image, window.width(), window.height());
}