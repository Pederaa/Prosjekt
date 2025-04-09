#include "LaserTurtleWindow.h"
#include "gameRunner.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "std_lib_facilities.h"
#include "constants.h"
#include "pageMode.h"

void LTWindow::startKnappCallback(){
    currentPageMode = pageMode::playing;
}

void LTWindow::creditsKnappCallback(){
    currentPageMode = pageMode::credits;
}

void LTWindow::tilbakeKnappCallback(){
    currentPageMode = pageMode::frontpage;
}

void LTWindow::updateFrame(){
    switch (currentPageMode){
        case pageMode::frontpage:
            this->draw_image({(WINDOW_WIDTH-LOGO_SIZE)/2+LOGO_OFFCENTERX, (WINDOW_HEIGH-LOGO_SIZE)/2+LOGO_OFFCENTERY}, logo, LOGO_SIZE, LOGO_SIZE);
            startKnapp.setVisible(true);
            creditsKnapp.setVisible(true);
            tilbakeKnapp.setVisible(false);
            break;
        case pageMode::credits:
            startKnapp.setVisible(false);
            creditsKnapp.setVisible(false);
            tilbakeKnapp.setVisible(true);
            this->draw_text({(WINDOW_WIDTH-52*4)/2 + 10, (WINDOW_HEIGH-50)/2-55 + TAKKPAGE_YOFFSET}, "Takk til ...", TDT4102::Color::black, 50);
            this->draw_text({(WINDOW_WIDTH-32*20)/2, WINDOW_HEIGH/2-10 + TAKKPAGE_YOFFSET}, "Yuliya Pauliukevich (klyaksun) på Vecteezy.com for eksplosjonsanimasjonene");
            this->draw_text({(WINDOW_WIDTH-32*20)/2, WINDOW_HEIGH/2+20 + TAKKPAGE_YOFFSET}, "M DANIEL (danilcool78457001) på Vecteezy.com for skilpaddespriten");
            this->draw_text({(WINDOW_WIDTH-15*20)/2, WINDOW_HEIGH/2+50 + TAKKPAGE_YOFFSET}, "ChatGPT for hjelp med å lage logoen");
            this->draw_text({(WINDOW_WIDTH-3*20)/2, WINDOW_HEIGH/2+80 + TAKKPAGE_YOFFSET}, "meg");
            break;
        case pageMode::settingDifficulty:
            startKnapp.setVisible(false);
            creditsKnapp.setVisible(false);
            tilbakeKnapp.setVisible(false);
            break;
        case pageMode::playing:
            startKnapp.setVisible(false);
            creditsKnapp.setVisible(false);
            tilbakeKnapp.setVisible(false);
            runGame(*this);
            break;
        }

    this->next_frame();
}

LTWindow::LTWindow() : AnimationWindow(0, 30, WINDOW_WIDTH, WINDOW_HEIGH, GAME_NAME){
    currentPageMode = pageMode::frontpage;
    //list = TDT4102::DropdownList({100, 100}, 300, 30, difficult);

    startKnapp.setCallback([this](){this->startKnappCallback();});
    startKnapp.setButtonColor(buttonColor);
    this->add(startKnapp);

    creditsKnapp.setCallback([this](){this->creditsKnappCallback();});
    creditsKnapp.setButtonColor(buttonColor);
    this->add(creditsKnapp);

    tilbakeKnapp.setCallback([this](){this->tilbakeKnappCallback();});
    tilbakeKnapp.setButtonColor(buttonColor);
    this->add(tilbakeKnapp);
}