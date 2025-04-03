#include "numBomb.h"

numBomb::numBomb(std::vector<int> lanes){
    random_device rd;
    default_random_engine generator(rd());
    xPosition = lanes[(generator()%(lanes.size()))] - width/2;
    speed = (generator()%2 + 2 );
    image = TDT4102::Image("images/bomb2.png"); 

    question = getSingleDigitPositiveNumQuestion();
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