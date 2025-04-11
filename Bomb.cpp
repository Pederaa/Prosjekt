#include "Bomb.h"
#include "LaserTurtleWindow.h"
#include "std_lib_facilities.h"
#include <random>
#include <algorithm>
#include <cctype>
#include <string>
#include <quary.h>


int Bomb::posY(){
    return this->y;
}

int Bomb::posX(){
    return this->x;
}

std::string Bomb::Answer(){
    return quary.answer;
}

void Bomb::moveDown(LTWindow& window){
    y += speed;
    drawTekstBoks(window);
}

void Bomb::drawTekstBoks(LTWindow& window){
    window.draw_image({x, y}, image, width, height);

    if (quary.question.length() < 4){
        window.draw_text({x+30, y+40}, quary.question, textColor, 20, textFont);
        return;
    }
    else if(quary.question.length() < 10){
        window.draw_text({x+25, y+40}, quary.question, textColor, 20, textFont);
        return;
    }
    else{
        int numOfSpaces = std::ranges::count(quary.question, ' ') + 1;

        int spaces[numOfSpaces];
        int i=0;

        for (int letter = 0; letter < quary.question.length(); letter++){
            if (quary.question[letter] == ' '){
                spaces[i] = letter;
                i++;
            }
        }
        spaces[numOfSpaces-1] = quary.question.length();

        int prevIndex = 0;
        vector<int> h;
        vector<std::string> g;
        for (int i =0; i < numOfSpaces; i++){
            if (spaces[i] - prevIndex >= 9){
                g.push_back(quary.question.substr(prevIndex, spaces[i-1]-prevIndex));
                prevIndex = spaces[i-1]+1;
            }
        }
        g.push_back(quary.question.substr(prevIndex, spaces[numOfSpaces]-spaces[numOfSpaces-1]));

        int y_center = y+50;
        int y_top = y_center - 14*g.size()/2;
        for (int i =0; i < g.size(); i++){
            window.draw_text({x+15, y_top+i*14}, g.at(i), textColor, 15, textFont);
        }

        return;
    }
}

Bomb::Bomb(){
    //image = TDT4102::Image("images/bomb2.png"); 
}