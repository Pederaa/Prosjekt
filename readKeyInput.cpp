#include "animationWindow.h"
#include "std_lib_facilities.h"

void getCharInput(TDT4102::AnimationWindow& window, std::string& t){
    if (window.is_key_down(KeyboardKey::A)){
        cout << "AAAAAA" << endl;
        t += "A";
    }
    else if (window.is_key_down(KeyboardKey::B)){
        cout << "BBBBB" << endl;
        t += "B";
    }
}