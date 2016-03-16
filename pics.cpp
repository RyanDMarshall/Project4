/**
 * pics.cpp
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
#include <cctype>
#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

using namespace std;

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints an opening message.
 */
void printOpener();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a closing message.
 */
void printCloser();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a menu.
 */
void printMenu();

/**
 * Requires: ins is in good state.
 * Modifies: cin, ins.
 * Effects:  Closes ins if it is open. Keeps reading filename from the user
 *           (and appends .txt) until the file is successfully opened.
 *           Returns the name of the file that was opened.
 */
string openFile(ifstream& ins);

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns str with all of its alphabetical characters lowercased.
 */
string tolower(string str);

/**
 * Requires: Nothing.
 * Modifies: cin, drawer.
 * Effects:
 *     Opens a file
 *     Start with a blank canvas (drawer)
 *     Start reading from file.  For each line....
 *        Read the 1st character to determine shape
 *        Read the shape:  L reads a line, C reads a circle, T read a triangle
 *            R reads a rectangle.
 *            For any other character, clears drawer and prints
 *            "Error in input file: " << [character already read]
 *            << [all chars remaining on the line] << endl;
 *        Draw shape on canvas
 *     Close file
 *     Print "[Loaded filename]"
 */
void loadFile(Graphics& drawer);

/**
 * Requires: Nothing.
 * Modifies: cout, drawer.
 * Effects:
 *     Read filename from user
 *     concatenate filename with .bmp
 *     Write image to file.
 *     Print "[Wrote filename]"
 */
void writeFile(const Graphics& drawer);

int main()
{
    Graphics drawer;
    string command;
    printOpener();
    printMenu();

    // read first command from user
    cin >> command;
    cout << endl;
    command = tolower(command);

    // read user's input until he or she quits
    while (command != "quit")
    {
        if (command == "load")
        {
            loadFile(drawer);
        }
        else if (command == "write")
        {
            writeFile(drawer);
        }
        else
        {
            cout << "Invalid command" << endl << endl;
        }

        printMenu();

        // read next command
        cin >> command;
        cout << endl;
        command = tolower(command);
    }

    printCloser();

    return 0;
}

void writeFile(const Graphics& drawer)
{
    string fileName = "";

    cin >> fileName;

    fileName = fileName + ".bmp";
    
    drawer.writeFile(fileName);

    cout << "[Wrote " << fileName << ']' << endl;
}


void loadFile(Graphics& drawer)
{
    ifstream input_file;

    string fileName = openFile(input_file);

    drawer.clear();

    while (!input_file.eof()) {
        
        string fullLine = "";
        char firstChar;

        input_file >> firstChar;
    
        Line line;
        Circle circle;
        Triangle triangle;
        Rectangle rectangle;

        switch (firstChar) {
            case 'L':
                line.read(input_file);
                line.draw(drawer);
                break;
            case 'C':
                circle.read(input_file);
                circle.draw(drawer);
                break;
            case 'T':
                triangle.read(input_file);
                triangle.draw(drawer);
                break;
            case 'R':
                rectangle.read(input_file);
                rectangle.draw(drawer);
                break;
            default:
                getline(input_file, fullLine);
                cout << "Error in input file: " << firstChar << fullLine << endl;
                break;
        }
    }

    cout << endl;

    input_file.close();

    cout << "[Loaded " << fileName << ']' << endl;
}

string tolower(string str)
{
    for (int i = 0; i < str.length(); i++) {
        str.at(i) = tolower(str.at(i));
    }

    return str;
}


// Don't change the implementations below!

void printMenu()
{
    cout << "Command:            Description:" << endl
         << "--------            ------------" << endl
         << "load filename       Loads data from a txt file" << endl
         << "write filename      Creates a bmp image from data" << endl
         << "quit                Quits the program" << endl << endl;
}

void printOpener()
{
    cout << "=================================================" << endl
         << "               Welcome to CoolPics" << endl
         << "=================================================" << endl << endl;
}

void printCloser()
{
    cout << "=================================================" << endl
         << "            Thanks for using CoolPics!" << endl
         << "=================================================" << endl;
}

string openFile(ifstream& ins)
{
    string fileName;

    // close stream if open
    if (ins.is_open())
    {
        ins.clear();
        ins.close();
    }

    // get filename
    cin >> fileName;
    fileName = fileName + ".txt";
    ins.open(fileName);

    // keep retrying if failed to open
    while (ins.fail())
    {
        cout << "Error in opening " << fileName
             << ". Enter another file name: ";
        ins.clear();
        cin >> fileName;
        fileName = fileName + ".txt";
        ins.open(fileName);
    }

    return fileName;
}
