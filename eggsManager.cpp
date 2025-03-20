#include "eggsManager.h"
#include "Egg.h"
#include "AnimationWindow.h"
#include "std_lib_facilities.h"

static std::vector<Egg> eggs;
void initlizeEggs(){
    eggs.push_back(Egg(200));
    eggs.push_back(Egg(500));
    eggs.push_back(Egg(1000));
    eggs.push_back(Egg(1300));
}

void drawEggs(TDT4102::AnimationWindow& window){
    for (Egg egg : eggs){
        std::cout << "EGG" << std::endl;
        egg.drawEgg(window);
    }
}