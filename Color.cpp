/**
 * Color.cpp
 *
 * EECS 183, Winter 2016
 * Project 4: CoolPics
 *
 * Ryan Marshall
 * Brandon Freudenstein
 *
 * ryanmars@umich.edu
 * bfreud@umich.edu
 *
 * This program provides the implementation necessary to draw basic graphical
 * representations of shapes (i.e. circles, lines, triangles, and rectangles)
 * to a .bmp file. The program will also be able to read in data from .txt
 * files, which allows for efficient rendering of graphics.
 */

#include "Color.h"

// Default Constructor. Sets all color values to 0.
Color::Color() {
    
    red = 0;
    green = 0;
    blue = 0;

    return;
}

/* Non-default constructor. Checks range of values and sets 
 * them to their respective colors. */
Color::Color(int redVal, int greenVal, int blueVal) {
    
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);

    return;
}

/* All following set and get functions set values to, or get values
 * from, their respective class data members. */
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

/* Reads colors into temporary variables, then checks the range of these
 * and sets those values equal to their respective colors. */
void Color::read(istream& ins) {

    int redColor, blueColor, greenColor;

    ins >> redColor >> greenColor >> blueColor;

    red = checkRange(redColor);
    green = checkRange(greenColor);
    blue = checkRange(blueColor);

    return;
}

// Writes the colors to the output stream
void Color::write(ostream& outs) {

    outs << ' ' << red << ' ' << green << ' ' << blue << ' ';
    
    return;
}

/* Checks that the value for the colors is within the range [0,255].
 * If the value is negative, returns 0. If it is greater than 255, 
 * returns 255. */
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