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
	RectangularPrism *box = new RectangularPrism(0, 0.5, 0, 0, 2, 4, 2);
	box->setColor(0, 0, 1);
	addShape(box);
	TriangularPrism *tri = new TriangularPrism(0, 2.5, -0.5, 0, 1, .5, .7, 2);
	tri->setColor(0, 0, 1);
	addShape(tri);
	TrapezodialPrism *trap = new TrapezodialPrism(0, 2.5, 0, 0,  10, 3, 4, 1, 20);
	trap->setColor(1,1,1);
	addShape(trap);
	Cylinder *flwheel = new Cylinder();
	flwheel->setColor(0,0,0);
	addShape(flwheel);
	Cylinder *frwheel = new Cylinder();
	frwheel->setColor(0, 0, 0);
	addShape(frwheel);
	Cylinder *blwheel = new Cylinder();
	blwheel->setColor(0, 0, 0);
	addShape(blwheel);
	Cylinder *brwheel = new Cylinder();
	brwheel->setColor(0, 0, 0);
	addShape(brwheel);

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
