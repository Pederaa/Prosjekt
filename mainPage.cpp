#include "mainPage.h"
#include "gameRunner.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "std_lib_facilities.h"
#include "constants.h"

static bool should_run_game = false;

struct mainWindow : public TDT4102::AnimationWindow {
    mainWindow();
    void startKnappCallback();

    private:
        TDT4102::Button startKnapp;
};

void mainWindow::startKnappCallback(){
    should_run_game = true;
}

mainWindow::mainWindow()
    : AnimationWindow(0, 30, WINDOW_WIDTH, WINDOW_HEIGH, GAME_NAME),
    startKnapp{{400, 400}, 200, 200, "Start"} {
        startKnapp.setCallback(std::bind(&mainWindow::startKnappCallback, this));
        add(startKnapp);
    }

void openMainPage(){
    auto window = mainWindow();

    while(!window.should_close()){
        if (should_run_game){
            runGame(window);
        }

        window.next_frame();
    }
}