/**
 * Point.cpp
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

#include "Point.h"
#include "utility.h"

// Default constructor. Sets point to (0,0).
Point::Point() {
    
    x = 0;
    y = 0;

    return;
}

// Non-default constructor. Sets x and y equal to the checked xVal and yVal.
Point::Point(int xVal, int yVal) {
    
    x = checkRange(xVal);
    y = checkRange(yVal);

    return;
}

/* All following set and get functions set values to, or get values
 * from, their respective class data members. */
void Point::setX(int xVal) {
    
    x = checkRange(xVal);

    return;
}

int Point::getX() {
    
    return x;
}

void Point::setY(int yVal) {
    
    y = checkRange(yVal);

    return;
}

int Point::getY() {
    
    return y;
}

// Reads in a point, taking into account formatting (parentheses, and a comma)
void Point::read(istream& ins) {
    
    char format;

    ins >> format >> x >> format >> y >> format;

    return;
}

/* Checks the values of x and y one last time, and writes those to the
 * output stream, in format (x,y). */
void Point::write(ostream& outs) {
    
    x = checkRange(x);
    y = checkRange(y);

    outs << '(' << x << ',' << y << ')';

    return;
}

/* Checks that the values are between 0 and DIMENSION (100). If the value 
 * is less than 0, returns 0. If it is greater than or equal to DIMENSION,
 * returns (DIMENSION - 1). */
int Point::checkRange(int val) {

    if (val < 0) {
        return 0;
    }
    else if (val >= DIMENSION) {
        return (DIMENSION - 1);
    }
    else {
        return val;
    }
}

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}

