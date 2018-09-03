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

MyVehicle::MyVehicle() :Vehicle(x_, y_, z_ , rotation_)
{
	RectangularPrism *box = new RectangularPrism(0, 20, 0, 20, 40, 20);
	addShape(box);
	TriangularPrism *tri = new TriangularPrism(10, 20, 0, 20, 20, 0.5, 10);
	addShape(tri);
	TrapezodialPrism *trap = new TrapezodialPrism(0, 40, 0, 10, 3, 4, 1, 20);
	addShape(trap);
	Cylinder *flwheel = new Cylinder();
	addShape(flwheel);
	Cylinder *frwheel = new Cylinder();
	addShape(frwheel);
	Cylinder *blwheel = new Cylinder();
	addShape(blwheel);
	Cylinder *brwheel = new Cylinder();
	addShape(brwheel);

}

void MyVehicle::draw()
{
	glPushMatrix();
	glTranslated(x, y, z);
		

	glPopMatrix();
}
