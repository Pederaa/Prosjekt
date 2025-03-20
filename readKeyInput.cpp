#include "animationWindow.h"
#include "std_lib_facilities.h"

static bool isKeyDown = false;
void getCharInput(TDT4102::AnimationWindow& window, std::string& t){
    if (window.is_key_down(KeyboardKey::A)){
        if(!isKeyDown){
            t += "A";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::B)){
        if(!isKeyDown){
            t += "B";
            isKeyDown = true;
        }
    }
    else{
        isKeyDown = false;
    }
}