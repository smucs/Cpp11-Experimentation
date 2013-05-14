#include "Robot.h"

Robot::Robot()
{
   
}

Robot::Robot(Robot&& temp)
{
    //yoik, stole your resources ;-D
    for(Robot::ColourItr it = temp.begin(); it != temp.end(); ++it)
    { 
    	addColour(*it);
    }
}

Robot::Robot(Robot& old)
{
    for(Robot::ColourItr it = old.begin(); it != old.end(); ++it)
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
