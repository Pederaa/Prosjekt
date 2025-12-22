#pragma once
#include "LaserTurtleWindow.h"
#include "constants.h"
// #include "AnimationWindow.h"
// #include "headers/widgets/Button.h"
// #include "widgets/DropdownList.h"
#include "pageMode.h"
#include "difficulty.h"
#include <SFML/Window.hpp>

class LTWindow : sf::Window {
    public:
        LTWindow();
        void startKnappCallback();
        void creditsKnappCallback();
        void tilbakeKnappCallback();

        // TDT4102::Image logo = TDT4102::Image("images/updated_logo.png");
        // TDT4102::Color buttonColor = TDT4102::Color::silver;
        // TDT4102::Color buttonTextColor = TDT4102::Color::black;
        vector<string> bannedPhrases;

        int randInt();
        random_device rd;
        default_random_engine g;
        bool should_close();

        void updateFrame();
        pageMode currentPageMode;
        difficulty diff;
        bool gameOver;
        int bombsSpawned;
        int delayEndFrames;
    
    private:
        // TDT4102::Button startKnapp {{(WINDOW_WIDTH-200)/2, (WINDOW_HEIGH-BUTTON_HEIGHT)/2+15}, (int)BUTTON_WIDTH, (int)BUTTON_HEIGHT, "Start"};
        // TDT4102::Button creditsKnapp {{(WINDOW_WIDTH-BUTTON_WIDTH)/2, (WINDOW_HEIGH-BUTTON_HEIGHT)/2 + 15 + 50}, BUTTON_WIDTH, BUTTON_HEIGHT, "Takk"};
        // std::vector<std::string> difficult {"Barneskole", "Videregående", "TDT4102"};

        // TDT4102::Button tilbakeKnapp {{(WINDOW_WIDTH-BUTTON_WIDTH)/2, (WINDOW_HEIGH-BUTTON_HEIGHT)/2 + 15 + 50+50+30 + TAKKPAGE_YOFFSET}, BUTTON_WIDTH, BUTTON_HEIGHT, "Tilbake"};
    };