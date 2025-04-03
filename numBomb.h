#pragma once
#include "Bomb.h"
#include "quary.h"

class numBomb : Bomb {

    public:
        numBomb(std::vector<int> lanes);
        Quary getSingleDigitPositiveNumQuestion();
};

