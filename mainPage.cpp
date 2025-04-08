#include "mainPage.h"
#include "gameRunner.h"
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "std_lib_facilities.h"
#include "constants.h"
#include "pageMode.h"

static pageMode currentPageMode;
void startKnappCallback(){
    currentPageMode = pageMode::playing;
}

void creditsKnappCallback(){
    currentPageMode = pageMode::credits;
}

void tilbakeKnappCallback(){
    currentPageMode = pageMode::frontpage;
}

void openMainPage(){
    currentPageMode = pageMode::frontpage;
    auto window = AnimationWindow(0, 30, WINDOW_WIDTH, WINDOW_HEIGH, GAME_NAME);

    TDT4102::Image logo = TDT4102::Image("images/updated_logo.png");
    TDT4102::Color color = TDT4102::Color::silver;

    TDT4102::Button startKnapp {{(WINDOW_WIDTH-200)/2, (WINDOW_HEIGH-BUTTON_HEIGHT)/2 + 15}, BUTTON_WIDTH, BUTTON_HEIGHT, "Start"};
    startKnapp.setCallback(startKnappCallback);
    startKnapp.setButtonColor(color);
    window.add(startKnapp);
    
    TDT4102::Button creditsKnapp {{(WINDOW_WIDTH-BUTTON_WIDTH)/2, (WINDOW_HEIGH-BUTTON_HEIGHT)/2 + 15 + 50}, BUTTON_WIDTH, BUTTON_HEIGHT, "Takk"};
    creditsKnapp.setCallback(creditsKnappCallback);
    creditsKnapp.setButtonColor(color);
    window.add(creditsKnapp);

    TDT4102::Button tilbakeKnapp {{(WINDOW_WIDTH-BUTTON_WIDTH)/2, (WINDOW_HEIGH-BUTTON_HEIGHT)/2 + 15 + 50+50+30 + TAKKPAGE_YOFFSET}, BUTTON_WIDTH, BUTTON_HEIGHT, "Tilbake"};
    tilbakeKnapp.setCallback(tilbakeKnappCallback);
    tilbakeKnapp.setButtonColor(color);
    window.add(tilbakeKnapp);



    while(!window.should_close()){
        switch (currentPageMode){
        case pageMode::frontpage:
            window.draw_image({(WINDOW_WIDTH-LOGO_SIZE)/2+LOGO_OFFCENTERX, (WINDOW_HEIGH-LOGO_SIZE)/2+LOGO_OFFCENTERY}, logo, LOGO_SIZE, LOGO_SIZE);
            startKnapp.setVisible(true);
            creditsKnapp.setVisible(true);
            tilbakeKnapp.setVisible(false);
            break;
        case pageMode::credits:
            startKnapp.setVisible(false);
            creditsKnapp.setVisible(false);
            tilbakeKnapp.setVisible(true);
            window.draw_text({(WINDOW_WIDTH-52*4)/2 + 10, (WINDOW_HEIGH-50)/2-55 + TAKKPAGE_YOFFSET}, "Takk til ...", TDT4102::Color::black, 50);
            window.draw_text({(WINDOW_WIDTH-32*20)/2, WINDOW_HEIGH/2-10 + TAKKPAGE_YOFFSET}, "Yuliya Pauliukevich (klyaksun) på Vecteezy.com for eksplosjonsanimasjonene");
            window.draw_text({(WINDOW_WIDTH-32*20)/2, WINDOW_HEIGH/2+20 + TAKKPAGE_YOFFSET}, "M DANIEL (danilcool78457001) på Vecteezy.com for skilpaddespriten");
            window.draw_text({(WINDOW_WIDTH-15*20)/2, WINDOW_HEIGH/2+50 + TAKKPAGE_YOFFSET}, "ChatGPT for hjelp med å lage logoen");
            window.draw_text({(WINDOW_WIDTH-3*20)/2, WINDOW_HEIGH/2+80 + TAKKPAGE_YOFFSET}, "meg");
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
            runGame(window);
            break;
        }
        
        window.next_frame();
    }
}