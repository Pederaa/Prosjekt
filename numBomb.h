#pragma once
#include "Bomb.h"
#include "quary.h"


class numBomb : public Bomb {
    public:
        numBomb(std::vector<int> lanes);
        ~numBomb(){};
        Quary getSingleDigitPositiveNumQuestion();
};
