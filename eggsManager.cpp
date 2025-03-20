#include "eggsManager.h"
#include "Egg.h"
#include "AnimationWindow.h"
#include "std_lib_facilities.h"

static std::vector<Egg> eggs;
void initlizeEggs(int lanes[]){
    for (int i=0; i<sizeof(lanes); i++) {
        eggs.push_back(lanes[i]);
    }
}

void drawEggs(TDT4102::AnimationWindow& window){
    for (Egg egg : eggs){
        egg.drawEgg(window);
    }
}