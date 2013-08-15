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

    cout << "MyRobot the Robot colours after construction:" << endl;
   for(Robot::ColourItr it = myRobot.begin(); it !=myRobot.end(); ++it)
   {
       cout << "RGB<" << (*it)->getRed() << ",";
       cout << (*it)->getGreen() << ",";
       cout << (*it)->getBlue() << ">" << endl;
   }


    //Create a colour and add it 
    RGB bob2(0,255,0);
    myRobot.addColour(bob2);

    //Add a lot of colours
    
    myRobot.addColour(shared_ptr<RGB>(new RGB(255,0,255)));
    myRobot.addColour(shared_ptr<RGB>(new RGB(255,255,255)));
    myRobot.addColour(shared_ptr<RGB>(new RGB(0,0,0)));


   cout << "MyRobot the Robot colours before delete:" << endl;
   for(Robot::ColourItr it = myRobot.begin(); it !=myRobot.end(); ++it)
   {
       cout << "RGB<" << (*it)->getRed() << ",";
       cout << (*it)->getGreen() << ",";
       cout << (*it)->getBlue() << ">" << endl;
   }

   cout << "Deleting bob2 <" << bob2.getRed() << "," << bob2.getGreen() << "," << bob2.getBlue() << ">" << endl;
   myRobot.deleteColour(bob2);

   cout << "MyRobot the Robot colours after delete:" << endl;
   for(Robot::ColourItr it = myRobot.begin(); it !=myRobot.end(); ++it)
   {
       cout << "RGB<" << (*it)->getRed() << ",";
       cout << (*it)->getGreen() << ",";
       cout << (*it)->getBlue() << ">" << endl;
   }


 
}
