#pragma once
#include "AnimationWindow.h"
#include <random>
#include "LaserTurtleWindow.h"

void runGame(LTWindow& window);
void addBombs(std::default_random_engine& generator, std::vector<int> lanes);
void drawBombs(TDT4102::AnimationWindow& window);
bool checkIfGuessIsCorrect(std::string guess);
void drawExplotions(TDT4102::AnimationWindow& window);
void drawLasers(TDT4102::AnimationWindow& window);
void removeLineAtX(int x);
void drawTurtle(TDT4102::AnimationWindow& window);
void checkIfGameOver(LTWindow& window, bool& gameOver);