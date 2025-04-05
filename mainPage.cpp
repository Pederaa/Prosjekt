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

    private:
        TDT4102::Button startKnapp;
};

void mainWindow::startKnappCallback(){
    currentPageMode = pageMode::playing;
}

mainWindow::mainWindow()
    : AnimationWindow(0, 30, WINDOW_WIDTH, WINDOW_HEIGH, GAME_NAME),
    startKnapp{{400, 400}, 200, 200, "Start"} {
        startKnapp.setCallback(std::bind(&mainWindow::startKnappCallback, this));
        add(startKnapp);
    }

void openMainPage(){
    currentPageMode = pageMode::frontpage;
    auto window = mainWindow();

    while(!window.should_close()){
        if (currentPageMode == pageMode::playing){
            runGame(window);
        }

        window.next_frame();
    }
}