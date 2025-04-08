#include "textBomb.h"
#include "quary.h"

textBomb::textBomb(std::vector<int> lanes){
    speed = 1;
    default_random_engine generator(rd());
    x = lanes[(generator()%(lanes.size()))] - width/2;
    
    quary = getTextQuary();
}

Quary textBomb::getTextQuary(){
    default_random_engine generator(rd());

    return textQuaryArray[generator()%(sizeof(textQuaryArray)/sizeof(Quary))];
}