#pragma once
#include "std_lib_facilities.h"

// Vindu
#define WINDOW_WIDTH 1300 //Bildene skal dimasnjoneres slik at 1 bildepiksel er 2*2 spillpiksler. 
#define WINDOW_HEIGH 600
#define GAME_NAME "Laserturtle"
constexpr int BEGIN_LANES[] = {100, 400, 800, 1100};


// Spillets gang
#define MAX_NUMBER_OF_BOMBS 25
#define QUOTE_PROBABILITY 8

// Forside
#define LOGO_SIZE 600
#define LOGO_OFFCENTERX -20
#define LOGO_OFFCENTERY -100
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 20


// Takkeside
#define TAKKPAGE_YOFFSET -100


// Input-skjerm
#define TYPINGSCREEN_HEIGHT 50
#define TYPINGSCREEN_WIDTH 200
#define TYPINGSCREEN_BOTTOMMARGIN 30

#define TYPINGSCREEN_TEXTSIZE 20


//Bomber
#define BOMB_SPEED 2
#define BOMB_INITIALY 0
#define BOMB_HEIGHT 100
#define BOMB_WIDTH 100

#define BOMB_CENTERCORRECTION_X 50
#define BOMB_CENTERCORRECTION_Y 50


//Sklpadde
#define TURTLE_SIZE 200
#define TURTLE_XOFFSET -107
#define TURTLE_YOFFSET -68


//Laser
#define LASER_CANNON_LENGTH 50
#define LASER_CANNON_X WINDOW_WIDTH/2
#define LASER_CANNON_Y WINDOW_HEIGH-150
#define LASER_MAXFRAME_INDEX 7


//Explotion
#define EXPLOTION_MAXFRAME_INDEX 15
#define EXPLOTION_WIDTH 130
#define EXPLOTION_HEIGHT 130

//Eggs
#define EGGS_MAXHP 3
#define EGGS_Y 500
