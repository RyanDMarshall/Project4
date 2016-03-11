/**
 * Point.cpp
 *
 * EECS 183, Winter 2016
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include "Point.h"
#include "utility.h"

// TODO: implement two constructors, setX, getX, setY, getY, read, write.

Point::Point() {
    
    x = 0;
    y = 0;

    return;
}

Point::Point(int xVal, int yVal) {
    
    x = checkRange(xVal);
    y = checkRange(yVal);

    return;
}

void Point::setX(int xVal) {
    
    x = xVal;

    return;
}

int Point::getX() {
    
    return x;
}

void Point::setY(int yVal) {
    
    y = yVal;

    return;
}

int Point::getY() {
    
    return y;
}

void Point::read(istream& ins) {
    
    char format;

    ins >> format >> x >> format >> y >> format;

    return;
}

void Point::write(ostream& outs) {
    
    cout <<'(' << x << ',' << y << ')';

    return;
}

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

// Your code goes above this line.
// Don't change the implementations below!

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

