#include "eggsManager.h"
#include "gameRunner.h"
#include "AnimationWindow.h"
#include "std_lib_facilities.h"

Egg::Egg(int xPos){
    x = xPos;
}

void Egg::drawEgg(TDT4102::AnimationWindow& window){
    switch(hp){
        case 3:
            window.draw_rectangle({x-10-5, y}, 10, 20, fillColor);
            window.draw_rectangle({x, y}, 10, 20, fillColor);
            window.draw_rectangle({x+10+5, y}, 10, 20, fillColor);
            break;

        case 2:
            window.draw_rectangle({x-10-2, y}, 10, 20, fillColor);
            window.draw_rectangle({x+3, y}, 10, 20, fillColor);
            break;

        case 1:
            window.draw_rectangle({x, y}, 10, 20, fillColor);
            break;

        case 0:
            removeLineAtX(x);
            break;
    }
}


static std::vector<Egg> eggs;
void initlizeEggs(std::vector<int> lanes){
    for (int i=0; i<lanes.size(); i++) {
        eggs.push_back(Egg(lanes[i]));
    }
}

void drawEggs(TDT4102::AnimationWindow& window){
    //cout << "Antall egg: " << eggs.size() << endl;
    auto it = eggs.begin();
    while (it != eggs.end()){
        (*it).drawEgg(window);
        it++;
    }
}

int getHeightOfeggs(){
    return eggs.front().get_y();
}

void damageEggAtXPosition(int x){
    auto it = eggs.begin();
    while (it != eggs.end()){
        if ((*it).get_x() == x + 50){
            (*it).removeHP();
            break;
        }
        it++;
    }
}

void eraseEgg(int x){
    //cout << "Slett egg" << endl;
    for (int i = 0; i < eggs.size(); i++){
        if(eggs.at(i).get_x() == x - 50){
            eggs.erase(eggs.begin() + i);
            return;
        }
    }
}