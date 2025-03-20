#include "animationWindow.h"
#include "std_lib_facilities.h"

static bool isKeyDown = false;
void getCharInput(TDT4102::AnimationWindow& window, std::string& typeText){
    if (window.is_key_down(KeyboardKey::A)){
        if(!isKeyDown){
            typeText += "A";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::B)){
        if(!isKeyDown){
            typeText += "B";
            isKeyDown = true;
        }
    }

    else if (window.is_key_down(KeyboardKey::ENTER)){
        if(!isKeyDown){
            std::cout << "Gjetter: " << typeText << std::endl;
            typeText = "";
        }
    }
    else{
        isKeyDown = false;
    }
}