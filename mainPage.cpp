#include "mainPage.h"
#include "gameRunner.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "std_lib_facilities.h"
#include "constants.h"
#include "pageMode.h"

static pageMode currentPageMode;

struct mainWindow : public TDT4102::AnimationWindow {
    mainWindow();
    void startKnappCallback();

    TDT4102::Button startKnapp;
};

void mainWindow::startKnappCallback(){
    currentPageMode = pageMode::playing;
    startKnapp.setVisible(false);
}

mainWindow::mainWindow()
    : AnimationWindow(0, 30, WINDOW_WIDTH, WINDOW_HEIGH, GAME_NAME),
    startKnapp{{(WINDOW_WIDTH-200)/2, (WINDOW_HEIGH-50)/2 + 50}, 200, 50, "Start"} {
        startKnapp.setCallback(std::bind(&mainWindow::startKnappCallback, this));
        startKnapp.setButtonColor(TDT4102::Color::silver);
        add(startKnapp);
    }

void openMainPage(){
    currentPageMode = pageMode::frontpage;
    auto window = mainWindow();

    while(!window.should_close()){
        switch (currentPageMode){
        case pageMode::frontpage:
            window.startKnapp.setVisible(true);
            break;
        case pageMode::settingDifficulty:
            window.startKnapp.setVisible(false);
            break;
        case pageMode::playing:
            runGame(window);
            break;
        }
        
        window.next_frame();
    }
}