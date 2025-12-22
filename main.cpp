#include "headers/std_lib_facilities.h"
#include "headers/LaserTurtleWindow.h"

int main() {
    LTWindow ltw;
    while (!ltw.should_close()){
        ltw.updateFrame();
    }
    return 0;
}