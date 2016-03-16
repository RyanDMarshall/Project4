/**
 * Color.cpp
 *
 * EECS 183, Winter 2016
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include "Color.h"

Color::Color() {
    
    red = 0;
    green = 0;
    blue = 0;

    return;
}

Color::Color(int redVal, int greenVal, int blueVal) {
    
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);

    return;
}

void Color::setRed(int redVal) {
    
    red = checkRange(redVal);
    
    return;
}

int Color::getRed() {
    
    return red;
}

void Color::setGreen(int greenVal) {

    green = checkRange(greenVal);
    
    return;
}

int Color::getGreen() {

    return green;
}

void Color::setBlue(int blueVal) {
    
    blue = checkRange(blueVal);
    
    return;
}

int Color::getBlue() {

    return blue;
}

void Color::read(istream& ins) {

    int redColor, blueColor, greenColor;

    ins >> redColor >> greenColor >> blueColor;

    red = checkRange(redColor);
    green = checkRange(greenColor);
    blue = checkRange(blueColor);

    return;
}

void Color::write(ostream& outs) {

    outs << ' ' << red << ' ' << green << ' ' << blue << ' ';
    
    return;
}

int Color::checkRange(int val) {
    if (val < 0) {
        return 0;
    }
    else if (val > 255) {
        return 255;
    }
    else {
        return val;
    }
}

// Your code goes above this line.
// Don't change the implementations below!
  
istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}