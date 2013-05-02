#ifndef ROBOT_H
#define ROBOT_H

#include "RGB.h"

#include <memory>

//dirty - but ...
using namespace std;

class Robot
{
private:
    shared_ptr<RGB> colour;
public:
    Robot();
    Robot(RGB&);
    ~Robot();

    void setColour(RGB&);
    RGB& getColour();

};

#endif
