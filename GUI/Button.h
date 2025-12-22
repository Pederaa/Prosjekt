#include "Button.cpp"
#include "GUI/Color.h"

class Button {
    Color buttonColor = GUI::RED;

    public:
        void drawButton();  //TODO: Lag disse funksjonene
        void hoverButton();
        void onClick();
};
