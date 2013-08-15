#ifndef ROBOT_H
#define ROBOT_H

#include "RGB.h"

#include <memory>
#include <vector>

//dirty - but ...
using namespace std;

class Robot
{
private:
    vector<shared_ptr<RGB>> colours;
public:
    Robot();
    Robot(Robot&&);
    Robot(Robot&); //this is probably wrong
    Robot(const Robot&);
    Robot(RGB&); 
    Robot(shared_ptr<RGB>);
    ~Robot();

    void addColour(RGB&);
    void addColour(shared_ptr<RGB>);
    void deleteColour(RGB&);
    void deleteColour(shared_ptr<RGB>);
    //RGB& getColour();
    //

    typedef typename std::vector<shared_ptr<RGB>>::iterator ColourItr;
    typedef typename std::vector<shared_ptr<RGB>>::const_iterator ConstColourItr;
    ColourItr begin() { return colours.begin(); }
    ColourItr end() { return colours.end(); }

   ConstColourItr begin() const { return colours.begin(); } 
   ConstColourItr end() const {return colours.end(); }

};

#endif
