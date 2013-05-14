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

    RGB bob2(0,255,0);
    myRobot.addColour(bob2);

    cout << "Second colour added R-0, G-255 & B-0" << endl;

    //RGB& fred = myRobot.getColour();
    //Replacing this with iterator   

    cout << "MyRobot the Robot says:" << endl;
    for(Robot::ColourItr it = myRobot.begin(); it !=myRobot.end(); ++it)
    {
        cout << "Red " << (*it)->getRed() << endl;
        cout << "Blue " << (*it)->getBlue() << endl;
        cout << "Green " << (*it)->getGreen() << endl;
    }

//AnotherRobot tests the copy construcotr, he will break myRobot
    Robot anotherRobot = std::move(myRobot); //my thinking is this will 
                                             //fire the move constructor
    
    //RGB& eric = anotherRobot.getColour();
    //Replacing this with iterator
   
    cout << "AnotherRobot says:" << endl;

    for(Robot::ColourItr it = anotherRobot.begin(); it !=anotherRobot.end(); ++it)
    {
        cout << "Red " << (*it)->getRed() << endl;
        cout << "Blue " << (*it)->getBlue() << endl;
        cout << "Green " << (*it)->getGreen() << endl;
    }

    cout << "MyRobot the Robot now says:" << endl;
    for(Robot::ColourItr it = myRobot.begin(); it !=myRobot.end(); ++it)
    {
        cout << "Red " << (*it)->getRed() << endl;
        cout << "Blue " << (*it)->getBlue() << endl;
        cout << "Green " << (*it)->getGreen() << endl;
    }
    
    cout << "MyRobot is now broken, when we called move its resrouces were stolen" << endl << endl; 

    Robot roboCopy = anotherRobot; //calls copy constructor

    cout << "RoboCopy is a copy of Robot created with the copy constructor, anotherRobot modified after its creation. This roboCopy should therefore output the same list as the anotherRobot above" << endl;

    RGB freddie{255,0,0};
    anotherRobot.addColour(freddie);

    for(Robot::ColourItr it = roboCopy.begin(); it !=roboCopy.end(); ++it)
    {
        cout << "Red " << (*it)->getRed() << endl;
        cout << "Blue " << (*it)->getBlue() << endl;
        cout << "Green " << (*it)->getGreen() << endl;
    }

    cout << "AnotherRobot now says:" << endl;

    for(Robot::ColourItr it = anotherRobot.begin(); it !=anotherRobot.end(); ++it)
    {
        cout << "Red " << (*it)->getRed() << endl;
        cout << "Blue " << (*it)->getBlue() << endl;
        cout << "Green " << (*it)->getGreen() << endl;
    }
}
