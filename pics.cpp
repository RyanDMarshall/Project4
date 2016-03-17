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
 * This program provides the implementation necessary to draw basic graphical 
 * representations of shapes (i.e. circles, lines, triangles, and rectangles) 
 * to a .bmp file. The program will also be able to read in data from .txt 
 * files, which allows for efficient rendering of graphics.
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

/* Reads in a string name, concatenates ".bmp", and draws the file.
 * Prints which file was written. */
void writeFile(const Graphics& drawer)
{
    string fileName = "";
    cin >> fileName;
    fileName = fileName + ".bmp";
    
    drawer.writeFile(fileName);
    cout << "[Wrote " << fileName << ']' << endl;
}

/* Opens a file and checks that the program has access. If so, reads
 * line by line, drawing the function based on the data in the file. */
void loadFile(Graphics& drawer)
{
    ifstream input_file;

    // Declares a string to hold the name of the .txt file loaded.
    string fileName = openFile(input_file);

    drawer.clear();

    // Declares a variable to which the first character in the file is set.
    char firstChar;
    input_file >> firstChar;

    // Loops until the end of the file is reached, or some other error occurs.
    while (!input_file.fail()) {

        /* Checks if the first letter of the line is one of the expected:
         * 'L', 'C', 'T', 'R'. In each of these cases, declares the letter's
         * respective shape, reads the reaminder of the line, and draws the 
         * data given. In any other case, prints the line on which the error
         * occurred. */

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
                input_file.clear();
                string fullLine = "";
                getline(input_file, fullLine);
                cout << "Error in input file: " << firstChar << fullLine;
                cout << endl;
                break;
        }
    
        /* At the end of a line, reads in the next character available -
         * i.e., the first character of the next line. If the character
         * exists, the loop runs again. If it does not, the loop stops.*/
        input_file >> firstChar;
    }

    /* Once all data in the file has been read and drawn, closes the file and
     * prints which file the data was drawn from. */
    cout << endl;

    input_file.close();

    cout << "[Loaded " << fileName << ']' << endl;
}

string tolower(string str)
{
    /* Loops through each element of a string, setting each to the 
     * lowercased version of itself. */
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
