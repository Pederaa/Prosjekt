#pragma once
#include "AnimationWindow.h"
#include <random>

void runGame();
void drawBlocks(TDT4102::AnimationWindow& window, std::default_random_engine& generator, int lanes[]);
void checkIfGuessIsCorrect(std::string guess);
void drawExplotions(TDT4102::AnimationWindow& window);
void drawLasers(TDT4102::AnimationWindow& window);
