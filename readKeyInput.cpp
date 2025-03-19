#include "animationWindow.h"
#include "std_lib_facilities.h"

void getCharInput(TDT4102::AnimationWindow window, std::string& t){
    if (window.is_key_down(KeyboardKey::A)){
        std::cout << "AAAAAA" << std::endl;
    }
    else if (window.is_key_down(KeyboardKey::B)){
        std::cout << "BBBBB" << std::endl;
    }
}