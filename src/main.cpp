#include "LaserTurtleWindow.h"
#include "std_lib_facilities.h"

int main() {
    LTWindow ltw;
    while (!ltw.should_close()){
        ltw.updateFrame();
    }
    return 0;
}