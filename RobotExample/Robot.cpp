#include "Robot.h"

Robot::Robot()
{
   
}

Robot::Robot(RGB& col)
{
    colour = make_shared<RGB>(col);
}

Robot::~Robot()
{
   
}

void Robot::setColour(RGB& col)
{
   colour = make_shared<RGB>(col);
}

RGB& Robot::getColour()
{
   return *colour.get();
}
