/**
 * Circle.cpp
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

#include "Circle.h"
#include "Line.h"
#include "Graphics.h"
#include "utility.h"
#include <algorithm>

using namespace std;

Circle::Circle() {

    return;
}

// Non-default constructor. Checks to see if radius is positive.
Circle::Circle(Point pt, int r, Color c) {

    center = pt;
    radius = checkRadius(r);
    color = c;

    return;    
}

/* All following set and get functions set values to, or get values
 * from, their respective class data members. */
void Circle::setCenter(Point pt) {

    center = pt;

    return;
}

Point Circle::getCenter() {

    return center;
}

// Sets radius to the absolute value of r.
void Circle::setRadius(int r) {

    radius = checkRadius(r);

    return;
}

int Circle::getRadius() {

    return checkRadius(radius);
}

void Circle::setColor(Color c) {

    color = c;

    return;
}

Color Circle::getColor() {

    return color;
}

// Reads in the components of a circle.
void Circle::read(istream& ins) {
    
    ins >> center >> radius >> color;

    return;
}

// Writes the components to the output stream.
void Circle::write(ostream& outs) {

    outs << center << ' ' << radius << ' ' << color;

    return;
}

istream& operator >> (istream& ins, Circle& circle)
{
    circle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Circle circle)
{
    circle.write(outs);
    return outs;
}

void Circle::draw(Graphics & drawer)
{
    int radius = min(getRadius(), (int)DIMENSION);
    int error = -radius;
    int x = radius;
    int y = 0;
    Color c = getColor();
    
    while (x >= y)
    {
        plot8points(x, y, c, drawer);
        
        error += y;
        ++y;
        error += y;
        
        if (error >= 0)
        {
            error -= x;
            --x;
            error -= x;
        }
    }
}

int Circle::checkRadius(int radius)
{
    if (radius < 0)
    {
        return -1 * radius;
    }
    return radius;
}

void Circle::plot8points(int x, int y, Color c, Graphics& drawer)
{
    plot4points(x, y, c, drawer);
    if (x != y) plot4points(y, x, c, drawer);
}

void Circle::plot4points(int x, int y, Color c, Graphics& drawer)
{
    // cx and cy denote the offset of the circle center from the origin.
    int cx = getCenter().getX();
    int cy = getCenter().getY();
    
    Point pt1Start(cx - x, cy + y);
    Point pt1End(cx + x, cy + y);
    Line line1(pt1Start, pt1End, c);
    line1.draw(drawer);
    
    Point pt2Start(cx - x, cy - y);
    Point pt2End(cx + x, cy - y);
    Line line2(pt2Start, pt2End, c);
    line2.draw(drawer);
}

