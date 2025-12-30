#include "headers/LaserTurtleWindow.h"
#include "headers/gameRunner.h"
#include "headers/std_lib_facilities.h"
#include "headers/constants.h"
#include "headers/pageMode.h"
#include <filesystem>

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

LTWindow::LTWindow() : sf::Window(0, 30, WINDOW_WIDTH, WINDOW_HEIGH, GAME_NAME){
    currentPageMode = pageMode::frontpage;
    gameOver = false;
    bombsSpawned = 0;
    delayEndFrames = 0;

    string path_string = "banned_phrases.txt";
	filesystem::path file_path{path_string}; // Lager et path-objekt som leder til fila. 

	ifstream inputStream{file_path}; // Lager en stream til fila. 
	if (!inputStream){ //Sjekker om fila eksisterer 
		throw(2);
	}
	string nextPhrase;
	while (getline(inputStream, nextPhrase)){ // Skriver ut et ord av gangen. Man kan skrive ut en bokstav av gangen ved å endre nextWord til en char. 
		bannedPhrases.push_back(nextPhrase);
	}
    inputStream.close();

    startKnapp.setCallback([this](){this->startKnappCallback();});
    startKnapp.setButtonColor(buttonColor);
    startKnapp.setLabelColor(buttonTextColor);
    this->add(startKnapp);

    creditsKnapp.setCallback([this](){this->creditsKnappCallback();});
    creditsKnapp.setButtonColor(buttonColor);
    creditsKnapp.setLabelColor(buttonTextColor);
    this->add(creditsKnapp);

    tilbakeKnapp.setCallback([this](){this->tilbakeKnappCallback();});
    tilbakeKnapp.setButtonColor(buttonColor);
    tilbakeKnapp.setLabelColor(buttonTextColor);
    this->add(tilbakeKnapp);
}

int LTWindow::randInt(){
	default_random_engine generator(rd());
    return generator();
}
