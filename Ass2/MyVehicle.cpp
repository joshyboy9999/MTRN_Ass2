#include "MyVehicle.hpp"
#include "Vehicle.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "Cylinder.h"
#include "TrapezodialPrism.hpp"
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

MyVehicle::MyVehicle(double x_, double y_, double z_, double rotation_) :Vehicle(x_, y_, z_ , rotation_)
{
	/*RectangularPrism *box = new RectangularPrism(x_, y_, z_, );
	addShape(box);
	TriangularPrism *tri = new TriangularPrism();
	addShape(tri);
	TrapezodialPrism *trap = new TrapezodialPrism();
	addShape(trap);
	Cylinder *flwheel = new Cylinder();
	addShape(flwheel);
	Cylinder *frwheel = new Cylinder();
	addShape(frwheel);
	Cylinder *blwheel = new Cylinder();
	addShape(blwheel);
	Cylinder *brwheel = new Cylinder();
	addShape(brwheel);
	*/
}

void MyVehicle::draw()
{
	glPushMatrix();
		glTranslated(x, y, z);
		std::vector<Shape *>::iterator it;
		for (it = shapes.begin(); it != shapes.end(); it++) {
			(*it)->draw();
		}

	glPopMatrix();
}
