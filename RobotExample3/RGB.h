
//Crappy little class to manage a pointer in Robot, replace this with something?
//Templated class perhaps?

#ifndef RGB_H
#define RGB_H

class RGB
{
private:
    int r;
    int g;
    int b;
public:
    RGB();
    RGB(RGB&);
    RGB(int red, int green, int blue);
    ~RGB();
 
    int getRed();
    int getGreen();
    int getBlue();

    void setRed(int);
    void setBlue(int);
    void setGreen(int);

    void operator=(RGB&);
    bool operator==(RGB&);
};

#endif
