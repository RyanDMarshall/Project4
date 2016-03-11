/**
 * Triangle.cpp
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
#include "Triangle.h"
#include "Graphics.h"
#include "Shape.h"
#include <cmath>
using namespace std;

// TODO: implement three constructors, setColor, setVertexOne, getVertexOne,
//       setVertexTwo, getVertexTwo, setVertexThree, getVertexThree,
//       setVertexOneColor, getVertexOneColor, setVertexTwoColor,
//       getVertexTwoColor, setVertexThreeColor, getVertexThreeColor,
//       read, write.

Triangle::Triangle() {
    
    return;
}

Triangle::Triangle(Point pt1, Point pt2, Point pt3, Color color) {

    
}

/**
* Requires: nothing
* Modifies: vertexOne, vertexTwo, vertexThree,
*           vertexOneColor, vertexTwoColor, vertexThreeColor.
* Effects:  Overloaded constructor. Sets three vertices and three colors.
*/
Triangle(Point pt1, Color color1,
    Point pt2, Color color2,
    Point pt3, Color color3);

/**
* Requires: Nothing.
* Modifies: vertexOneColor, vertexTwoColor, vertexThreeColor.
* Effects:  Sets all three colors of triangle.
*/
void setColor(Color color);

/**
* Requires: Nothing.
* Modifies: vertexOne.
* Effects:  Sets vertex one of triangle.
*/
void setVertexOne(Point pt);

/**
* Requires: Nothing.
* Modifies: Nothing.
* Effects:  Returns vertex one of triangle.
*/
Point getVertexOne();

/**
* Requires: Nothing.
* Modifies: vertexOneColor.
* Effects:  Sets color of vertex one of triangle.
*/
void setVertexOneColor(Color color);

/**
* Requires: Nothing.
* Modifies: Nothing.
* Effects:  Returns color of vertex one of triangle.
*/
Color getVertexOneColor();

/**
* Requires: Nothing.
* Modifies: vertexTwo.
* Effects:  Sets vertex two of triangle.
*/
void setVertexTwo(Point pt);

/**
* Requires: Nothing.
* Modifies: Nothing.
* Effects:  Returns vertex two of triangle.
*/
Point getVertexTwo();

/**
* Requires: Nothing.
* Modifies: vertexTwoColor.
* Effects:  Sets color of vertex two of triangle.
*/
void setVertexTwoColor(Color color);

/**
* Requires: Nothing.
* Modifies: Nothing.
* Effects:  Returns color of vertex two of triangle.
*/
Color getVertexTwoColor();

/**
* Requires: Nothing.
* Modifies: vertexThree.
* Effects:  Sets vertex three of triangle.
*/
void setVertexThree(Point pt);

/**
* Requires: Nothing.
* Modifies: Nothing.
* Effects:  Returns vertex three of triangle.
*/
Point getVertexThree();

/**
* Requires: Nothing.
* Modifies: vertexThreeColor.
* Effects:  Sets color of vertex three of triangle.
*/
void setVertexThreeColor(Color color);

/**
* Requires: Nothing.
* Modifies: Nothing.
* Effects:  Returns color of vertex three of triangle.
*/
Color getVertexThreeColor();

/**
* Requires: ins is in good state.
* Modifies: ins, vertexOne, vertexTwo, vertexThree,
*           vertexOneColor, vertexTwoColor, vertexThreeColor.
* Effects:  Reads triangle in forms
*           v1 v2 v3 color
*           v1 v1Color v2 v2Color v3 v3Color
*/
void read(istream& ins);

/**
* Requires: outs is in good state.
* Modifies: outs.
* Effects:  Writes triangle in form
*           v1 v1Color v2 v2Color v3 v3Color
*/
void write(ostream& outs);

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Triangle& tri)
{
    tri.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Triangle tri)
{
    tri.write(outs);
    return outs;
}

void Triangle::draw (Graphics& drawer) {
    
    int xa = checkRange(getVertexOne().getX());
    int ya = checkRange(getVertexOne().getY());
    int xb = checkRange(getVertexTwo().getX());
    int yb = checkRange(getVertexTwo().getY());
    int xc = checkRange(getVertexThree().getX());
    int yc = checkRange(getVertexThree().getY());
    float red1 = (float)(getVertexOneColor().getRed()/255.0);
    float green1 = (float)(getVertexOneColor().getGreen()/255.0);
    float blue1 = (float)(getVertexOneColor().getBlue()/255.0);
    float red2 = (float)(getVertexTwoColor().getRed()/255.0);
    float green2 = (float)(getVertexTwoColor().getGreen()/255.0);
    float blue2 = (float)(getVertexTwoColor().getBlue()/255.0);
    float red3 = (float)(getVertexThreeColor().getRed()/255.0);
    float green3 = (float)(getVertexThreeColor().getGreen()/255.0);
    float blue3 = (float)(getVertexThreeColor().getBlue()/255.0);
    
    float a01, a02, a03, b01, b02, b03, c01, c02, c03, beta1, beta2, beta3;
    float lowX = 0, lowY = 0, highX = 0, highY = 0, i, j, R, G, B, t1, t2, t3;
    float triangleArea = 0;
    
    a01 = (float)(ya - yb);
    a02 = (float)(ya - yc);
    a03 = (float)(yb - yc);
    b01 = (float)(xb - xa);
    b02 = (float)(xc - xa);
    b03 = (float)(xc - xb);
    c01 = -(a01 * (xa+xb)+ b01 * (ya + yb)) / 2;
    c02 = -(a02 *(xa+xc) + b02 * (ya + yc)) / 2;
    c03 = -(a03 *(xb+xc) + b03 * (yb + yc)) / 2;
    
    if (evalFunc(xc,yc, (int)a01, (int)b01, (int)c01) < 0) {
        a01 = a01 * (-1);
        b01 = b01 * (-1);
        c01 = c01 * (-1);
    }
    if (evalFunc(xb,yb, (int)a02, (int)b02, (int)c02) < 0) {
        a02 = a02 * (-1);
        b02 = b02 * (-1);
        c02 = c02 * (-1);
    }
    if (evalFunc(xa,ya, (int)a03, (int)b03, (int)c03) < 0) {
        a03 = a03 * (-1);
        b03 = b03 * (-1);
        c03 = c03 * (-1);
    }
    if (xa > xb) { highX = (float)xa;  } else { highX = (float)xb; }
    if (xc > highX) { highX = (float)xc; }
    if (ya > yb) { highY = (float)ya; } else { highY = (float)yb; }
    if (yc > highY) { highY = (float)yc; }
    if (xa < xb) { lowX = (float)xa; } else { lowX = (float)xb; }
    if (xc < lowX) { lowX = (float)xc; }
    if (ya < yb) { lowY = (float)ya; } else { lowY = (float)yb; }
    if (yc < lowY) { lowY = (float)yc; }
    
    triangleArea = triArea(xa, ya, xb, yb, xc, yc);
    
    for (i = lowX; i < (highX+1); i++) {
        for (j = lowY; j < (highY+1); j++) {
            t1 = (float)evalFunc((int)i,(int)j, (int)a01, (int)b01, (int)c01);
            t2 = (float)evalFunc((int)i,(int)j, (int)a02, (int)b02, (int)c02);
            t3 = (float)evalFunc((int)i,(int)j, (int)a03, (int)b03, (int)c03);
            if ((t1 >= 0)&&(t2 >= 0)&&(t3 >= 0)){
                t1 = triArea(xb, yb, xc, yc, (int)i, (int)j);
                t2 = triArea(xc, yc, xa, ya, (int)i, (int)j);
                t3 = triArea(xa, ya, xb, yb, (int)i, (int)j);
                beta1 = triArea(xb, yb, xc, yc, (int)i, (int)j)/triangleArea;
                beta2 = triArea(xc, yc, xa, ya, (int)i, (int)j)/triangleArea;
                beta3 = triArea(xa, ya, xb, yb, (int)i, (int)j)/triangleArea;
                R = (beta1*red1 + beta2*red2 + beta3*red3) * 255;
                G = (beta1*green1 + beta2*green2 + beta3*green3) * 255;
                B = (beta1*blue1 + beta2*blue2 + beta3*blue3) * 255;
                drawer.setPixel((int)i,(int)j,Color((int)R,(int)G,int(B)));
            }
        }
    }
}

int Triangle::checkRange(int val)
{
    if (val < 0)
        return 0;
    else if (val > DIMENSION)
        return DIMENSION;
    else
        return val;
}

int Triangle::evalFunc(int x, int y, int a, int b, int c) {
    int e = a*x+b*y+c;
    return(e);
}

float Triangle::triArea(int xa, int ya, int xb, int yb, int xref, int yref) {
    xa -= xref;
    xb -= xref;
    ya -= yref;
    yb -= yref;
    return((float)(sqrt(pow((double)(yb*xa)-(xb*ya), (double)2))*0.5));
}

