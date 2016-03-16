/**
* test.cpp
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
* <#Description#>
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h" 

using namespace std;

void test_rectangle();

int main() {

    Point a(10,10);
    Point b(50,50);
    Color c(0,0,0);
    Color d(10,10,10);
    Color e(20,20,20);
    Color f(255,255,255);

    Rectangle g(a,b,c,d,e,f);
    Rectangle h;
    Rectangle i;
    
    ifstream input_file;
    input_file.open("circles.txt");

    h.read(input_file);
    i.read(input_file);
    
    input_file.close();
    
    cout << g.getStart() << ' ' << g.getEnd() << ' ' << g.getColorTopLeft() << ' ' << g.getColorTopRight() <<
            ' ' << g.getColorBottomRight() << ' ' << g.getColorBottomLeft() << endl;

    cout << h.getStart() << ' ' << h.getEnd() << ' ' << h.getColorTopLeft() << ' ' << h.getColorTopRight() <<
        ' ' << h.getColorBottomRight() << ' ' << h.getColorBottomLeft() << endl;

    cout << i.getStart() << ' ' << i.getEnd() << ' ' << i.getColorTopLeft() << ' ' << i.getColorTopRight() <<
        ' ' << i.getColorBottomRight() << ' ' << i.getColorBottomLeft() << endl;

    return 0;
}

void test_rectangle() {

    Point a(10, 10);
    Point b(50, 50);
    Color c(0, 0, 0);
    Color d(10, 10, 10);
    Color e(20, 20, 20);
    Color f(255, 255, 255);

    Rectangle g(a, b, c, d, e, f);
    Rectangle h;
    Rectangle i;

    ifstream input_file;
    input_file.open("circles.txt");

    h.read(input_file);
    i.read(input_file);

    input_file.close();

    cout << g.getStart() << ' ' << g.getEnd() << ' ' << g.getColorTopLeft() << ' ' << g.getColorTopRight() <<
        ' ' << g.getColorBottomRight() << ' ' << g.getColorBottomLeft() << endl;

    cout << h.getStart() << ' ' << h.getEnd() << ' ' << h.getColorTopLeft() << ' ' << h.getColorTopRight() <<
        ' ' << h.getColorBottomRight() << ' ' << h.getColorBottomLeft() << endl;

    cout << i.getStart() << ' ' << i.getEnd() << ' ' << i.getColorTopLeft() << ' ' << i.getColorTopRight() <<
        ' ' << i.getColorBottomRight() << ' ' << i.getColorBottomLeft() << endl;


}