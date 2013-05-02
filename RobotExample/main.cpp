// Simple robot example, based on Robot teaching programming metaphore.  
// Uses a shared_ptr (C++ smart pointer) in the Robot class
//
// Compilation:
// make 
// or to remove all old files "make clean"
// To run:
// ./robot
//

#include "RGB.h"
#include "Robot.h"

//std libraries
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    RGB bob(0,0,255);

    Robot myRobot(bob);

    cout << "Robot created with R-0, G-0 & B-255" << endl;

    RGB& fred = myRobot.getColour();

    cout << "MyRobot the Robot says:" << endl;
    cout << "Red " << fred.getRed() << endl;
    cout << "Blue " << fred.getBlue() << endl;
    cout << "Green " << fred.getGreen() << endl;

    Robot anotherRobot = std::move(myRobot); //my thinking is this will 
                                             //fire the move constructor
    
    RGB& eric = anotherRobot.getColour();
    cout << "AnotherRobot says:" << endl;
    cout << "Red " << eric.getRed() << endl;
    cout << "Blue " << eric.getBlue() << endl;
    cout << "Green " << eric.getGreen() << endl;
}
