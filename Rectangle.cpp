/**
 * Rectangle.cpp
 *
 * EECS 183, Winter 2016
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

Rectangle::Rectangle() {

    return;
}

Rectangle::Rectangle(Point pt1, Point pt2, Color color) {

    start = pt1;
    end = pt2;
    colorTopLeft = colorTopRight = colorBottomLeft = colorBottomRight = color;

    return;
}

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

    ins >> start >> end >> color;
    
    if (!ins.eof()) {

        ins >> testColor;

        if (ins.fail()) {

            ins.clear();

            colorTopLeft = colorTopRight = colorBottomLeft = colorBottomRight = color;
        }
        else {

            colorTopLeft = color;
            colorTopRight = testColor;
            ins >> colorBottomRight >> colorBottomLeft;
        }
    }
    else {

        colorTopLeft = colorTopRight = colorBottomLeft = colorBottomRight = color;
    }
    
    return;
}

void Rectangle::write(ostream& outs) {

    outs << start << ' ' << end << ' ' << colorTopLeft << ' ' << 
            colorTopRight << ' ' << colorBottomRight << ' ' << colorBottomLeft;

    return;
}

// Your code goes above this line.
// Don't change the implementations below!

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

