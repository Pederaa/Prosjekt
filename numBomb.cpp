#include "numBomb.h"
#include "Bomb.h"
#include "quary.h"

numBomb::numBomb(std::vector<int> lanes){
    random_device rd;
    default_random_engine generator(rd());
    x = lanes[(generator()%(lanes.size()))] - width/2;
    quary = getSingleDigitPositiveNumQuestion();
}

Quary numBomb::getSingleDigitPositiveNumQuestion(){
    random_device rd;
    default_random_engine generator(rd());

    int a = generator()%10+1;
    int b = generator()%10+1;

    Quary q;
    q.question = to_string(a) + "+" + to_string(b);
    q.answer = to_string(a+b);

    return q;
}