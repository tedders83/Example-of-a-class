/* Example of a class called Circle, which is used to demonstrate how classes work and show the difference between
	public and private variables

	by tedders83
*/

#include <iostream>
#include <string>

#include "Circle.h"

using namespace std; // just so I don't have to do std::string for every string, which looks confusing

int main(){

	// make a circle, no user input
	Circle c = Circle("Awesome Circle", 3, 2, 2);

	// print the circle's name using function first function defined in the .cpp file, which just prints the name using couta
	cout << "The circle's name is: ";
	c.printName();
	cout << "\n";

	// using the second, which returns a string
	cout << "Once again, the circle's name is: " <<  c.getName() << "\n";

	// since name is a public variable in Circle, we can access it directly as well
	cout << "And finally, the circle's name is: " << c.name << "\n\n";

	// since the name variable is in public, we can change the name directly:
	c.name = "Even Better Circle";
	
	// print it again
	cout << "The Circle's name is now: ";
	c.printName();
	cout << "\n\n";

	// test the print properties function
	c.printProperties();

	// since the radius and the x and y coordinates are in private, changing them directly wont work, the foilowing attempt to change
	// the radius and location will cause the program to not compile, whereas if radius, x_coordinate, and y_coordinate were under public
	// in Circle.h, this attempt would work
	// c.radius = 5;
	// c.x_coordinate = 10;
	// c.y_coordinate = 15;

	// similarly, trying to simply print the radius and coordinates by accessing them directly will not work if they are in private
	// cout << "The circle's radius is: " << c.radius << "and it's location is: (" << c.x_coordinate << ", " << c.y_coordinate << ").\n\n";

	// since we defined ways to change the radius and location in the public section of Circle's definition, we can use those to change them
	c.changeRadius(5);
	c.changeLocation(6, 7);

	// and now we see if it worked
	cout << "\nThe circle's properties have changed! \n";
	c.printProperties();

	// Since radius, x_coordinate, and y_coordinate are private, the following attempt to copy the circle will not work in main:
	// Circle d = Circle(c.name, c.radius, c.x_coordinate, c.y_coordinate);

	// Instead we use the copy function we defined in public:
	Circle d = c.makeCopy();

	// Now let's change d's properties:
	d.name = "Second Circle";
	d.changeRadius(9);
	d.changeLocation(1, 2);

	// And see if it worked
	cout << "\nNow we have two circles:\nFirst: ";
	c.printProperties();
	cout << "Second: ";
	d.printProperties();

	// Now let's make a copy of the second circle with 0 radius and at the origin (0,0)
	// since changePropertiesToZero() is private, the following will not work in main:
	// Circle e = d.makeCopy();
	// e.changePropertiesToZero();

	// so we use the public function makeZeroCopy();
	Circle e = d.makeZeroCopy();

	// And see if it worked
	cout << "\nNow we have a copy of the second circle with no radius located at the origin:\n";
	e.printProperties();
	cout << endl;

	system("pause");
	return(0);
}
