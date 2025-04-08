#include "numBomb.h"
#include "Bomb.h"
#include "quary.h"

numBomb::numBomb(std::vector<int> lanes){
    default_random_engine generator(rd());
    x = lanes[(generator()%(lanes.size()))] - width/2;
    
    quary = getSingleDigitPositiveNumQuestion();
}

Quary numBomb::getSingleDigitPositiveNumQuestion(){
    random_device rd;
    default_random_engine generator(rd());

    int a = generator()%10+1;
    int b = generator()%10+1;

    std::string w = to_string(a) + "+" + to_string(b);
    std::string f = to_string(a+b);

    Quary q(w, f);
    return q;
}