#include "Robot.h"

#include <iostream>

using std::cout;
using std::endl;

Robot::Robot()
{
   
}

Robot::Robot(Robot&& temp)
{
    cout << "Move constructor called" << endl;
    //yoik, stole your resources ;-D
    colours=std::move(temp.colours);
}

Robot::Robot(Robot& old)
{   
    cout << "Copy constructor called" << endl;
    for(Robot::ColourItr it = old.begin(); it != old.end(); ++it)
    {
        addColour(*it);
    }
}

Robot::Robot(const Robot& old)
{
    cout << "Const copy constructor called" << endl;
    for(Robot::ConstColourItr it = old.begin(); it != old.end(); ++it)
    {
        addColour(*it);
    }
}

Robot::Robot(RGB& col)
{
   addColour(col);
}

Robot::~Robot()
{
   
}

void Robot::addColour(RGB& col)
{
   shared_ptr<RGB> temp = make_shared<RGB>(col);
   colours.push_back(temp);
}

void Robot::addColour(shared_ptr<RGB> col)
{
   colours.push_back(col);
}

//Replaced with iterators?
//RGB& Robot::getColour()
//{
//   return *colour.get();
//}
