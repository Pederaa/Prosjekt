#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include "gameRunner.h"

#include <unordered_map>

// Map som kartlegger alle keyinputsene til sine char-verdier
std::unordered_map<KeyboardKey, char> keyMap = {
    {KeyboardKey::A, 'A'}, {KeyboardKey::B, 'B'}, {KeyboardKey::C, 'C'}, {KeyboardKey::D, 'D'}, {KeyboardKey::E, 'E'},
    {KeyboardKey::F, 'F'}, {KeyboardKey::G, 'G'}, {KeyboardKey::H, 'H'}, {KeyboardKey::I, 'I'}, {KeyboardKey::J, 'J'},
    {KeyboardKey::K, 'K'}, {KeyboardKey::L, 'L'}, {KeyboardKey::M, 'M'}, {KeyboardKey::N, 'N'}, {KeyboardKey::O, 'O'},
    {KeyboardKey::P, 'P'}, {KeyboardKey::Q, 'Q'}, {KeyboardKey::R, 'R'}, {KeyboardKey::S, 'S'}, {KeyboardKey::T, 'T'},
    {KeyboardKey::U, 'U'}, {KeyboardKey::V, 'V'}, {KeyboardKey::W, 'W'}, {KeyboardKey::X, 'X'}, {KeyboardKey::Y, 'Y'},
    {KeyboardKey::Z, 'Z'}, {KeyboardKey::SPACE, ' '},
    {KeyboardKey::KEY_0, '0'}, {KeyboardKey::KEY_1, '1'}, {KeyboardKey::KEY_2, '2'}, {KeyboardKey::KEY_3, '3'},
    {KeyboardKey::KEY_4, '4'}, {KeyboardKey::KEY_5, '5'}, {KeyboardKey::KEY_6, '6'}, {KeyboardKey::KEY_7, '7'},
    {KeyboardKey::KEY_8, '8'}, {KeyboardKey::KEY_9, '9'}
};

// Dersom spilleren trykker på en knapp, skal den verdien skrives til typeText, 
// men bare èn gang. Dersom spilleren løfter fingeren av tasten og trykker den inn igjen, 
// eller trykker på en annen knapp skal en ny verdi skirves inn. 

//Verdi som husker om knappen var inne ved forrige iterering.
static bool isKeyPressed = false; 

//Variabel som husker hva den forrige nøkkelen som ble trykket var. 
static KeyboardKey prevKey = KeyboardKey::SPACE;

void getCharInput(TDT4102::AnimationWindow& window, std::string& typeText){
    //Backspace er den eneste spesielle tasten. Den sletter siste element i typetext. 
    if (window.is_key_down(KeyboardKey::BACKSPACE)){ 
        if((!isKeyPressed || prevKey != KeyboardKey::BACKSPACE) && !typeText.empty()){
            typeText = "";
        }
        prevKey = KeyboardKey::BACKSPACE;
        isKeyPressed = true;
        return;
    }

    // Her sjekkes alle tastene en etter en i keymappet. Dersom tasten er nede og 
    // den ikke var nede siden sist (eller evt. om det brukeren har trykket på en annen 
    // knapp så raskt at det ikke ble merket) skal tasten legges til
    for (const auto& [key, value] : keyMap) { 
        if (window.is_key_down(key)) {
            if (!isKeyPressed || key != prevKey){
                try{
                    typeText += value;
                    if (typeText == "HEIL HITLER"){
                        throw(88);
                    }

                // Her sjekker vi om det brukeren har skrevet inn matcher med noen av 
                // bombene i lufta. Da resettes innholdet i typeText
                if (checkIfGuessIsCorrect(typeText)){ 
                    typeText = "";
                }
                }
                catch(int errMess){
                    typeText = "";
                }
            }
            prevKey = key;
            isKeyPressed = true;
            return;
        }
    }

    // Dersom ingen av return-statementsene har blitt aktivert, skal denne variabelen bli false
    isKeyPressed = false;
    }