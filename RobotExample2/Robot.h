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
    Robot(Robot&);
    Robot(RGB&);
    Robot(shared_ptr<RGB>);
    ~Robot();

    void addColour(RGB&);
    void addColour(shared_ptr<RGB>);
    //RGB& getColour();
    //

    typedef typename std::vector<shared_ptr<RGB>>::iterator ColourItr;
//    typedef typename std::vector<shared_ptr<RGB>>::const_iterator const_colourItr;
    ColourItr begin() { return colours.begin(); }
    ColourItr end() { return colours.end(); }

//    const_colourItr begin() { return const colours.begin(); }
//    const_colourItr end() {return const colours.end(); }

};

#endif
