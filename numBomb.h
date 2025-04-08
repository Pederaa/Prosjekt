#pragma once
#include "Bomb.h"
#include "quary.h"


class numBomb : public Bomb {
    public:
        random_device rd;
        numBomb(std::vector<int> lanes);
        Quary getSingleDigitPositiveNumQuestion();
};
