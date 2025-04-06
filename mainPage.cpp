#include "mainPage.h"
#include "gameRunner.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "std_lib_facilities.h"
#include "constants.h"
#include "pageMode.h"

static pageMode currentPageMode;

struct mainWindow{
    mainWindow();
    void startKnappCallback();
    void creditsKnappCallback();

    TDT4102::AnimationWindow w;
    TDT4102::Button startKnapp;
    TDT4102::Button creditsKnapp;
    TDT4102::Image logo;
};

void startKnappCallback(){
    currentPageMode = pageMode::playing;
}

void creditsKnappCallback(){
    currentPageMode = pageMode::credits;
}
    
void openMainPage(){
    currentPageMode = pageMode::frontpage;
    auto window = AnimationWindow(0, 30, WINDOW_WIDTH, WINDOW_HEIGH, GAME_NAME);
    
    TDT4102::Button startKnapp {{(WINDOW_WIDTH-200)/2, (WINDOW_HEIGH-50)/2 + 50}, 200, 20, "Start"};
    TDT4102::Image logo = TDT4102::Image("images/logo.png");
    startKnapp.setCallback(startKnappCallback);
    startKnapp.setButtonColor(TDT4102::Color::silver);
    window.add(startKnapp);
    
    TDT4102::Button creditsKnapp {{(WINDOW_WIDTH-200)/2, (WINDOW_HEIGH-50)/2 + 50 + 50}, 200, 20, "credits"};


    while(!window.should_close()){
        switch (currentPageMode){
        case pageMode::frontpage:
            window.draw_image({(WINDOW_WIDTH-600)/2, WINDOW_HEIGH/2 -400}, logo, 600, 600);
            startKnapp.setVisible(true);
            break;
        case pageMode::settingDifficulty:
            startKnapp.setVisible(false);
            break;
        case pageMode::playing:
            startKnapp.setVisible(false);
            runGame(window);
            break;
        }
        
        window.next_frame();
    }
}