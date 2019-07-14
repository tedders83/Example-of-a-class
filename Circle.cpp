// The cpp file for Circle, defines all the functions from the header file

#include <iostream>
#include <string>

#include "Circle.h"

using namespace std;

// Constructor
Circle::Circle(string user_inputted_name, int user_inputted_radius, int user_inputted_x_coordinate, int user_inputted_y_coordinate){
	// set properties based on inputs
	name = user_inputted_name;
	radius = user_inputted_radius;
	x_coordinate = user_inputted_x_coordinate;
	y_coordinate = user_inputted_y_coordinate;
}

// Alternative constructor, does the same thing using an initializer list, you would need to delete or comment out the original
// constructor code in order to use this code
/*
Circle::Circle(string user_inputted_name, int user_inputted_radius, int user_inputted_x_coordinate, int user_inputted_y_coordinate) :
	name(user_inputted_name), radius(user_inputted_radius), x_coordinate(user_inputted_x_coordinate),
	y_coordinate(user_inputted_y_coordinate){
	// nothing needed here
};
*/


void Circle::printName(){
	// prints the name
	cout << name;
}


string Circle::getName(){
	// returns the name
	return name;
}

void Circle::printProperties(){
	// prints all the properties, note that radius, x_coordinate, and y_coordinate are not accessible outside of this file 
	// since they are under private in the header file, but they can be used anywhere in this file. This function is the 
	// only one I've written that prints them in main or could in the definition of another class that includes and uses 
	// the Circle class. The variable name could be used or changed in main or the definition of another class that includes
	// and uses the Circle class.
	cout << "The circle's name is: " << name << ". Its radius is: " << radius << ". Its location is: (" 
		<< x_coordinate << ", " << y_coordinate << ").\n";
}

void Circle::changeRadius(int new_radius){
	// changes the radius to the one in the parentheses, since the radius is private it can be changed directly here.
	// Since it is a public function, it can be used in main or the definition of another class that includes and uses the circle
	// class to change the radius
	radius = new_radius;
}

void Circle::changeLocation(int new_x_coordinate, int new_y_coordinate){
	// changes both the x and y coordinates, which are private variables. Is a public function so it can be used in main or another
	// class definition where Circles are included
	x_coordinate = new_x_coordinate;
	y_coordinate = new_y_coordinate;
}

Circle Circle::makeCopy(){
	// returns a copy of the circle
	return Circle(name, radius, x_coordinate, y_coordinate);
}

Circle Circle::makeZeroCopy(){
	// returns a copy of the circle with zero radius at origin, name stays the same
	// note that "this" is a pointer to the object using the function (or being defined, if used in the constructor). 
	// It does not refer to the new circle f!
	
	// make a copy first
	Circle f = this->makeCopy();
	
	// use the private function changeProperties to zero on f (note the following 2 lines could be condensed into 1 line
	f.changePropertiesToZero();
	return f;

	// or:
	// return f.changePropertiesToZero();
}

void Circle::changePropertiesToZero(){
	// private function, going to be used to copy a circle and change its properties to 0
	radius = 0;
	x_coordinate = 0;
	y_coordinate = 0;
}