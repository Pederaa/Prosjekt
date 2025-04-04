#pragma once
#include "std_lib_facilities.h"

// Vindu
constexpr int WINDOW_WIDTH = 1300; //Bildene skal dimasnjoneres slik at 1 bildepiksel er 2*2 spillpiksler. 
constexpr int WINDOW_HEIGH = 600;
constexpr std::string GAME_NAME = "Laserturtle";
constexpr int BEGIN_LANES[] = {100, 400, 800, 1100};

// Input-skjerm
constexpr int TYPINGSCREEN_HEIGHT = 50;
constexpr int TYPINGSCREEN_WIDTH = 200;
constexpr int TYPINGSCREEN_BOTTOMMARGIN = 0;

constexpr int TYPINGSCREEN_TEXTSIZE = 20;


//Bomber
constexpr int BOMB_SPEED = 2;
constexpr int BOMB_INITIALY = 0;
constexpr int BOMB_HEIGHT = 100;
constexpr int BOMB_WIDTH = 100;

constexpr int BOMB_CENTERCORRECTION_X = 50;
constexpr int BOMB_CENTERCORRECTION_Y = 50;


//Explotion
constexpr int EXPLOTION_MAXFRAME_INDEX = 15;
constexpr int EXPLOTION_WIDTH = 100;
constexpr int EXPLOTION_HEIGHT = 100;



//Laser
constexpr int LASER_CANNON_LENGTH = 100;
constexpr int LASER_MAXFRAME_INDEX = 10;


//Eggs
constexpr int EGGS_MAXHP = 3;
constexpr int EGGS_Y = 500;
