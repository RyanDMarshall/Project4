/**
 * Shape.h
 *
 * EECS 183, Winter 2016
 * Project 4: CoolPics
 *
 * Base class for all shapes.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "Graphics.h"

class Shape
{
public:
    /**
     * Requires: Nothing.
     * Modifies: drawer.
     * Effects:  Draws the shape.
     */
	virtual void draw(Graphics &drawer);
};

#endif

