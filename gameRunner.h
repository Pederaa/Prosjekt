#pragma once
#include "AnimationWindow.h"
#include <random>

void runGame(TDT4102::AnimationWindow& window);
void addBombs(std::default_random_engine& generator, std::vector<int> lanes);
void drawBombs(TDT4102::AnimationWindow& window);
void checkIfGuessIsCorrect(std::string guess);
void drawExplotions(TDT4102::AnimationWindow& window);
void drawLasers(TDT4102::AnimationWindow& window);
void removeLineAtX(int x);