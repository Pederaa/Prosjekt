#pragma once
#include "AnimationWindow.h"
#include "constants.h"
#include "std_lib_facilities.h"
#include "LaserTurtleWindow.h"
#include <list>

class Explotion{
    int x;
    int y;
    int frameIndex = 0;
    int maxIndex = EXPLOTION_MAXFRAME_INDEX;
    TDT4102::Image frame1 = TDT4102::Image("images/explotion_animtion2/frame1.png");
    TDT4102::Image frame2 = TDT4102::Image("images/explotion_animtion2/frame2.png");
    TDT4102::Image frame3 = TDT4102::Image("images/explotion_animtion2/frame3.png");
    TDT4102::Image frame4 = TDT4102::Image("images/explotion_animtion2/frame4.png");
    TDT4102::Image frame5 = TDT4102::Image("images/explotion_animtion2/frame5.png");
    TDT4102::Image frame6 = TDT4102::Image("images/explotion_animtion2/frame6.png");
    TDT4102::Image frame7 = TDT4102::Image("images/explotion_animtion2/frame7.png");

    public:
        Explotion(int xPos, int yPos);
        bool drawExplotion(TDT4102::AnimationWindow& window);
};

class Explotions {
    std::list<Explotion> explotions;

    public:
        void drawExplotions(LTWindow& window);

        auto begin() {return explotions.begin();}
        auto end() {return explotions.end();}
        auto erase(auto it) {return explotions.erase(it);}
        void push_back(Explotion ex) {explotions.push_back(ex);}
};