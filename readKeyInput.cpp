#include "animationWindow.h"
#include "std_lib_facilities.h"
#include <unordered_map>

std::unordered_map<KeyboardKey, char> keyMap = {
    {KeyboardKey::A, 'A'}, {KeyboardKey::B, 'B'}, {KeyboardKey::C, 'C'}, {KeyboardKey::D, 'D'}, {KeyboardKey::E, 'E'},
    {KeyboardKey::F, 'F'}, {KeyboardKey::G, 'G'}, {KeyboardKey::H, 'H'}, {KeyboardKey::I, 'I'}, {KeyboardKey::J, 'J'},
    {KeyboardKey::K, 'K'}, {KeyboardKey::L, 'L'}, {KeyboardKey::M, 'M'}, {KeyboardKey::N, 'N'}, {KeyboardKey::O, 'O'},
    {KeyboardKey::P, 'P'}, {KeyboardKey::Q, 'Q'}, {KeyboardKey::R, 'R'}, {KeyboardKey::S, 'S'}, {KeyboardKey::T, 'T'},
    {KeyboardKey::U, 'U'}, {KeyboardKey::V, 'V'}, {KeyboardKey::W, 'W'}, {KeyboardKey::X, 'X'}, {KeyboardKey::Y, 'Y'},
    {KeyboardKey::Z, 'Z'},
    {KeyboardKey::KEY_0, '0'}, {KeyboardKey::KEY_1, '1'}, {KeyboardKey::KEY_2, '2'}, {KeyboardKey::KEY_3, '3'},
    {KeyboardKey::KEY_4, '4'}, {KeyboardKey::KEY_5, '5'}, {KeyboardKey::KEY_6, '6'}, {KeyboardKey::KEY_7, '7'},
    {KeyboardKey::KEY_8, '8'}, {KeyboardKey::KEY_9, '9'}
};

static bool isKeyDown = false;
void getCharInput(TDT4102::AnimationWindow& window, std::string& typeText){

    for (const auto& [key, value] : keyMap) {
        if (window.is_key_down(key) && !isKeyDown) {
        typeText += value;
        isKeyDown = true;
        break;  // Prevent multiple key presses at once
        }
    }

    if (window.is_key_down(KeyboardKey::BACKSPACE)){
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