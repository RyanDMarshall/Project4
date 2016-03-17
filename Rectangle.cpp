/**
 * Rectangle.cpp
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

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

// Default costructor. Does nothing; returns nothing.
Rectangle::Rectangle() {

    return;
}

/* First non-default constructor. Sets the top left point and the bottom 
 * right point, then sets the colors of each corner (and thus the whole
 * rectangle) to color. */
Rectangle::Rectangle(Point pt1, Point pt2, Color color) {

    start = pt1;
    end = pt2;
    setColor(color);

    return;
}

// Second non-default constructor. Separately sets the colors of all corners.
Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
                     Color cBottomRight, Color cBottomLeft) {

    start = pt1;
    end = pt2;
    
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomLeft = cBottomLeft;
    colorBottomRight = cBottomRight;

    return;
}

/* All following set and get functions set values to, or get values
 * from, their respective class data members. */
void Rectangle::setStart(Point pt) {

    start = pt;

    return;
}

Point Rectangle::getStart() {

    return start;
}

void Rectangle::setEnd(Point pt) {

    end = pt;

    return;
}

Point Rectangle::getEnd() {

    return end;
}

// Sets all rectangle corners to color.
void Rectangle::setColor(Color color) {

    colorTopLeft = colorTopRight = colorBottomRight = colorBottomLeft = color;

    return;
}

void Rectangle::setColorTopLeft(Color color) {

    colorTopLeft = color;

    return;
}

Color Rectangle::getColorTopLeft() {

    return colorTopLeft;
}

void Rectangle::setColorTopRight(Color color) {
    
    colorTopRight = color;

    return;
}

Color Rectangle::getColorTopRight() {

    return colorTopRight;
}

void Rectangle::setColorBottomRight(Color color) {

    colorBottomRight = color;

    return;
}

Color Rectangle::getColorBottomRight() {

    return colorBottomRight;
}

void Rectangle::setColorBottomLeft(Color c) {

    colorBottomLeft = c;

    return;
}

Color Rectangle::getColorBottomLeft() {

    return colorBottomLeft;
}

void Rectangle::read(istream& ins) {

    Color color;
    Color testColor;

    // Reads in the three correct variables, then tests an extra one.
    ins >> start >> end >> color >> testColor;

    /* If the extra variable sends the input stream into a fail state, then
     * start, end, and color were sufficient, and so we use the case for the
     * first non-default constructor. I.e. we clear the stream and set all
     * corner colors to color. */
    if (ins.fail()) {
        
        ins.clear();
        setColor(color);
    }
    /* If the input stream does not enter a fail state, then start, end, 
     * and color were not sufficient, and so we use the case for the second
     * non-default constructor, set the colors we've read in to their
     * respective corners, and read in colors to the final two corners. */
    else {
        colorTopLeft = color;
        colorTopRight = testColor;

        ins >> colorBottomRight >> colorBottomLeft;
    }
    return;
}


// Writes the rectangle components to output stream.
void Rectangle::write(ostream& outs) {

    outs << start << ' ' << end << ' ' << colorTopLeft << ' ' << 
            colorTopRight << ' ' << colorBottomRight << ' ' << colorBottomLeft;

    return;
}

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());
    
    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);
    
    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}

