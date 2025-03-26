#include "std_lib_facilities.h"
#include "mainPage.h"

void PointCannonAt(int targetX, int targetY){
    int length = 100;

    int basePositionX = 300;
    int basePositionY = 500;

    float k = length/sqrt(pow(targetX - basePositionX, 2) + pow(targetY - basePositionY, 2));
    float tempX;
    if (basePositionX <= targetX){
        tempX = basePositionX + k*(targetX - basePositionX);
    }
    else{
        tempX = basePositionX - k*(targetX - basePositionX);
    }
    float tempY = basePositionY - k*(basePositionY - targetY);
    float endPositionX = static_cast<int>(std::round(tempX));
    float endPositionY =  static_cast<int>(std::round(tempY));

    cout << "{ k=" << k << "}" << endl;
    cout << "{" << tempX << ", " << tempY << "}" << endl;
    cout << "{" << endPositionX << ", " << endPositionY << ", 100=" << sqrt(pow(endPositionX - basePositionX, 2) + pow(endPositionX - endPositionY, 2)) << "}" << endl << endl;
}

int main() {
    //PointCannonAt(500, 300);

    openMainPage();
    return 0;
}

