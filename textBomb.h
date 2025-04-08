#pragma once
#include "Bomb.h"
#include "quary.h"
#include <unordered_map>

class textBomb : public Bomb{
    public:
        random_device rd;
        textBomb(std::vector<int> lanes);
        Quary getTextQuary();
};

static Quary textQuaryArray[] = {
    Quary("I am vengance. I am the knight...", "I AM BATMAN"),
    Quary("b...", "B"),
};