// The header file for Circle, basically a list of functions and variables that every Circle object will have


#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>

using namespace std;

class Circle{
public:
	// constructor
	Circle(string user_inputted_name, int user_inputted_radius, int user_inputted_x_coordinate, int user_inputted_y_coordinate);
	
	// we put the name in public to show how it can be changed if put in public
	string name;

	// function that prints the circle's name
	void printName();

	// function that returns the circle's name
	string getName();

	// function that prints  all the properties
	void printProperties();

	// functions that change the private variables for radius and coordinates
	void changeRadius(int new_radius);
	void changeLocation(int new_x_coordinate, int new_y_coordinate);

	// function that returns a copy of the circle
	Circle makeCopy();

	// function that returns a copy of the circle with 0 radius at origin, using private function changePropertiesToZero.
	// Note the circle's name stays the same
	Circle makeZeroCopy();

	void changePropertiesToZero();

private:
	// properties that can only be directly used or changed in Circle.cpp (or here, technically)
	int radius;
	int x_coordinate;
	int y_coordinate;

	// function that can only be used in Circle.cpp, makes radius and coordinates 0
	
};



#endif