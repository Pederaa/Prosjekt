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
    else if (window.is_key_down(KeyboardKey::C)){
        if(!isKeyDown){
            typeText += "C";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::D)){
        if(!isKeyDown){
            typeText += "D";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::E)){
        if(!isKeyDown){
            typeText += "E";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::F)){
        if(!isKeyDown){
            typeText += "F";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::G)){
        if(!isKeyDown){
            typeText += "G";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::H)){
        if(!isKeyDown){
            typeText += "H";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::I)){
        if(!isKeyDown){
            typeText += "I";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::J)){
        if(!isKeyDown){
            typeText += "J";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::K)){
        if(!isKeyDown){
            typeText += "K";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::L)){
        if(!isKeyDown){
            typeText += "L";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::M)){
        if(!isKeyDown){
            typeText += "M";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::N)){
        if(!isKeyDown){
            typeText += "N";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::O)){
        if(!isKeyDown){
            typeText += "O";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::P)){
        if(!isKeyDown){
            typeText += "P";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::Q)){
        if(!isKeyDown){
            typeText += "Q";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::R)){
        if(!isKeyDown){
            typeText += "R";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::S)){
        if(!isKeyDown){
            typeText += "S";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::T)){
        if(!isKeyDown){
            typeText += "T";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::U)){
        if(!isKeyDown){
            typeText += "U";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::V)){
        if(!isKeyDown){
            typeText += "V";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::W)){
        if(!isKeyDown){
            typeText += "W";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::X)){
        if(!isKeyDown){
            typeText += "X";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::Y)){
        if(!isKeyDown){
            typeText += "Y";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::Z)){
        if(!isKeyDown){
            typeText += "Z";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::KEY_0)){
        if(!isKeyDown){
            typeText += "0";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::KEY_1)){
        if(!isKeyDown){
            typeText += "1";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::KEY_2)){
        if(!isKeyDown){
            typeText += "2";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::KEY_3)){
        if(!isKeyDown){
            typeText += "3";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::KEY_4)){
        if(!isKeyDown){
            typeText += "4";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::KEY_5)){
        if(!isKeyDown){
            typeText += "5";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::KEY_6)){
        if(!isKeyDown){
            typeText += "6";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::KEY_7)){
        if(!isKeyDown){
            typeText += "7";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::KEY_8)){
        if(!isKeyDown){
            typeText += "8";
            isKeyDown = true;
        }
    }
    else if (window.is_key_down(KeyboardKey::KEY_9)){
        if(!isKeyDown){
            typeText += "9";
            isKeyDown = true;
        }
    }

    else if (window.is_key_down(KeyboardKey::BACKSPACE)){
        if(!isKeyDown && sizeof(typeText) >= 1){
            typeText.pop_back();
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