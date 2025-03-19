#include "animationWindow.h"
#include "std_lib_facilities.h"
#include "windowManager.h"

void clicked(){
    cout << "Hei" << std::endl;
}

void drawWindow(){
    TDT4102::AnimationWindow window; //Lager en instanse av et animasjonsvindu.
    window.wait_for_close();
    cout << "Vindu lukket" << endl;
}