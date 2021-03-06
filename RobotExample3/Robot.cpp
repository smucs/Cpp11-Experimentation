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
   //Freaks me out not clearing memory, but I think
   //this will actually allow me to get rid of it
   ColourItr it = this->begin();
   while(it != this->end())
   {
       (*it).reset(); //De-reference the iterator to get a shared pointer
       it = colours.erase(it); //this is the clever bit, when I delete the item using erase the current iterator is busted. 
   }
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

void Robot::deleteColour(RGB& old)
{
    ColourItr it = this->begin();
    while(it != this->end())
    {
        if((*(*it)) == old) //now this is ugly - de-reference the iterator and then the shared pointer ... I have my doubts. 
        {
            (*it).reset(); //de-ref the iterator and reset the pointer this (I think calls delete on the memory)
            it = colours.erase(it); //when you delete from a collection the iterator is broken, so the method returns a new one. 
        }
        else
        {
            ++it; //if we didn't trash the itterator increment it
        }   
    }
}

void Robot::deleteColour(shared_ptr<RGB> old)
{
    ColourItr it = this->begin();
    while(it != this->end())
    {
        if((*(*it)) == (*old)) //as above but also need to de-ref the shared pointer to get an itterator
        {
            (*it).reset();
            it = colours.erase(it);
        }
        else
        {
            ++it;
        }   
    }
}
//Replaced with iterators?
//RGB& Robot::getColour()
//{
//   return *colour.get();
//}
