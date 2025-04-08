#pragma once
#include "std_lib_facilities.h"

// Vindu
constexpr int WINDOW_WIDTH = 1300; //Bildene skal dimasnjoneres slik at 1 bildepiksel er 2*2 spillpiksler. 
constexpr int WINDOW_HEIGH = 600;
constexpr std::string GAME_NAME = "Laserturtle";
constexpr int BEGIN_LANES[] = {100, 400, 800, 1100};


// Forside
constexpr int LOGO_SIZE = 600;
constexpr int LOGO_OFFCENTERX = -20;
constexpr int LOGO_OFFCENTERY = -100;
constexpr int BUTTON_WIDTH = 200;
constexpr int BUTTON_HEIGHT = 20;


// Takkeside
constexpr int TAKKPAGE_YOFFSET = -100;


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

//Sklpadde
constexpr int TURTLE__SIZE = 200;
constexpr int TURTLE_XOFFSET = -107;
constexpr int TURTLE_YOFFSET = -68;


//Laser
constexpr int LASER_CANNON_LENGTH = 50;
constexpr int LASER_CANNON_X = WINDOW_WIDTH/2;
constexpr int LASER_CANNON_Y = WINDOW_HEIGH-150;
constexpr int LASER_MAXFRAME_INDEX = 7;


//Explotion
constexpr int EXPLOTION_MAXFRAME_INDEX = 15;
constexpr int EXPLOTION_WIDTH = 130;
constexpr int EXPLOTION_HEIGHT = 130;

//Eggs
constexpr int EGGS_MAXHP = 3;
constexpr int EGGS_Y = 500;
