#pragma once
#include "AnimationWindow.h"
#include <random>

void runGame();
void drawBlocks(TDT4102::AnimationWindow& window, default_random_engine& generator, int lanes[]);
