#pragma once
#include <random>
#include "headers/LaserTurtleWindow.h"

void runGame(LTWindow& window);
void addBombs(LTWindow& window, std::vector<int> lanes);
void drawBombs(LTWindow& window);
bool checkIfGuessIsCorrect(std::string guess);
void drawExplotions(LTWindow& window);
void drawLasers(LTWindow& window);
void removeLineAtX(int x);
void drawTurtle(LTWindow& window);
void checkIfGameOver(LTWindow& window);