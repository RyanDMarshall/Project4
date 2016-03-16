/**
* test.cpp
*
* EECS 183, Winter 2016
* Assignment 4
*
* Brandon Freudenstein
* bfreud
* Ryan Marshall
* ryanmars
*
* This is the test suite for all classes.
*/

#include "Point.h"
#include "Color.h"
#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

#include <iostream>
#include <fstream>
using namespace std;

void test_point(ifstream& file);
void test_color(ifstream& file);
void test_line(ifstream& file);
void test_triangle();
void test_circle();
void test_rectangle();

int main()
{
    ifstream input_file;
    input_file.open("data1.txt");
    test_point(input_file);
    test_color(input_file);
    test_line(input_file);
    test_triangle();
    test_circle();
    test_rectangle();

    return 0;
}

void test_point(ifstream& file)
{
    Point pt1;
    Point pt2;
    Point pt3;
    Point pt4;
    cout << pt1 << " (0, 0)" << endl;

    pt1.setX(15);
    pt1.setY(10);
    cout << pt1 << " (15, 10)" << endl;

    pt1.setX(-15);
    pt1.setY(-10);
    cout << pt1 << " (0, 0)" << endl;

    pt1.setX(150);
    pt1.setY(100);
    cout << pt1 << " (99, 99)" << endl;

    pt1.setX(20);
    pt1.setY(54);
    cout << pt1.getX() << " " << pt1.getY() << "  20 54" << endl;

    cout << "Testing read, compare to data1.txt" << endl;
    pt1.read(file);
    pt2.read(file);
    pt3.read(file);
    pt4.read(file);
    cout << pt1 << endl;
    cout << pt2 << endl;
    cout << pt3 << endl;
    cout << pt4 << endl;

    Point pt5(3, 5);
    cout << pt5 << " (3, 5)" << endl;
    Point pt6(-4, -150);
    cout << pt6 << " (0, 0)" << endl;
    Point pt7(900, 100);
    cout << pt7 << " (99, 99)" << endl;

    return;
}

void test_color(ifstream& file)
{
    Color color1;
    cout << color1 << " 0 0 0" << endl;

    color1.setRed(11);
    color1.setGreen(245);
    color1.setBlue(255);
    cout << color1 << " 11 245 255" << endl;

    color1.setRed(-2);
    color1.setBlue(-255);
    color1.setGreen(-1000);
    cout << color1 << " 0 0 0" << endl;

    color1.setRed(256);
    color1.setBlue(598);
    color1.setGreen(888);
    cout << color1 << " 255 255 255" << endl;

    Color color2(60, 209, 71);
    cout << color2 << " 60 209 71" << endl;
    cout << color2.getRed() << " " << color2.getGreen() << " " 
        << color2.getBlue() << " 60 209 71" << endl;

    Color color3(-1, -1, -1);
    Color color4(256, 256, 256);
    cout << color3 << " 0 0 0" << endl;
    cout << color4 << " 255 255 255" << endl;

    cout << "Testing read, compare to data1.txt" << endl;
    color1.read(file);
    color2.read(file);
    color3.read(file);
    cout << color1 << endl;
    cout << color2 << endl;
    cout << color3 << endl;

    return;
}

void test_line(ifstream& file)
{
    Line line1;
    cout << line1 << " (0, 0) (0, 0) 0 0 0" << endl;

    Point pt1(1, 1);
    Point pt2(3, 3);
    Color color1(12, 12, 12);
    Line line2(pt1, pt2, color1);
    cout << line2 << " (1, 1) (3, 3) 12 12 12" << endl;

    Point pt3(2, 2);
    Point pt4(4, 4);
    Color color2(13, 13, 13);
    line2.setStart(pt3);
    line2.setEnd(pt4);
    line2.setColor(color2);
    cout << line2 << " (2, 2) (4, 4) 13 13 13" << endl;
    cout << line2.getStart() << " " << line2.getEnd() << " "
        << line2.getColor() << " (2, 2) (4, 4) 13 13 13" << endl;

    cout << "Testing read, compare to data1.txt" << endl;
    line1.read(file);
    line2.read(file);
    cout << line1 << endl;
    cout << line2 << endl;
    file.close();

    cout << "Testing write, compare data2.txt to data1.txt" << endl;
    ofstream file2;
    file2.open("data2.txt");
    line1.write(file2);
    line2.write(file2);
    file2.close();
    return;
}

void test_triangle()
{
    Triangle tri1;

    Point pt1(3, 4);
    Point pt2(4, 7);
    Point pt3(3, 9);
    Color color1(50, 60, 70);
    Color color2(60, 70, 80);
    Color color3(70, 80, 90);

    Triangle tri2(pt1, pt2, pt3, color1);
    Triangle tri3(pt1, color1, pt2, color2, pt3, color3);

    cout << tri1 << endl;
    cout << tri2 << endl;
    cout << tri3 << endl;

    tri1.setColor(color2);
    cout << tri1 << endl;

    tri1.setVertexOne(pt1);
    tri1.setVertexTwo(pt2);
    tri1.setVertexThree(pt3);
    tri1.setVertexOneColor(color1);
    tri1.setVertexTwoColor(color2);
    tri1.setVertexThreeColor(color3);
    cout << tri1 << endl;

    cout << tri1.getVertexOne() << " " << tri1.getVertexTwo() << " " <<
        tri1.getVertexThree() << " " << tri1.getVertexOneColor() << " "
        << tri1.getVertexTwoColor() << " " << tri1.getVertexThreeColor();

    cout << "Testing read, compare to triangles.txt" << endl;
    ifstream ins;
    ins.open("triangles.txt");
    tri1.read(ins);
    tri2.read(ins);
    cout << tri1 << endl;
    cout << tri2 << endl;
    ins.close();
    
    cout << "Testing write, compare data2.txt to data1.txt" << endl;
    ofstream file;
    file.open("data2.txt");
    tri1.write(file);
    tri2.write(file);
    file.close();

    return;
}

void test_circle()
{
    Circle circ1;

    Point pt1(3, 4);
    Point pt2(4, 5);
    int r1 = 5;
    int r2 = -9;
    Color color1(50, 60, 70);
    Color color2(60, 70, 80);

    Circle circ2(pt1, r1, color1);
    Circle circ3(pt1, r2, color1);

    cout << circ1 << endl;
    cout << circ2 << endl;
    cout << circ3 << endl;

    circ1.setCenter(pt1);
    circ1.setRadius(r2);
    circ1.setColor(color1);
    cout << circ1 << endl;

    cout << circ1.getCenter() << " " << circ1.getRadius() << " " <<
        circ1.getColor();
    return;
}

void test_rectangle()
{
    Rectangle rec1;

    Point pt1(3, 4);
    Point pt2(4, 7);
    Color color1(50, 60, 70);
    Color color2(60, 70, 80);
    Color color3(70, 80, 90);
    Color color4(80, 90, 100);

    Rectangle rec2(pt1, pt2, color1);
    Rectangle rec3(pt1, pt2, color1, color2, color3, color4);

    cout << rec1 << endl;
    cout << rec2 << endl;
    cout << rec3 << endl;

    rec1.setColor(color2);
    cout << rec1 << endl;

    rec1.setStart(pt1);
    rec1.setEnd(pt2);
    rec1.setColorTopLeft(color1);
    rec1.setColorTopRight(color2);
    rec1.setColorBottomLeft(color3);
    rec1.setColorBottomRight(color4);
    cout << rec1 << endl;

    cout << rec1.getStart() << " " << rec1.getEnd() << " " <<
        rec1.getColorTopLeft() << " " << rec1.getColorTopRight() << " "
        << rec1.getColorBottomLeft() << " " << rec1.getColorBottomRight();
    return;
}
