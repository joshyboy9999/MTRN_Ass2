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

MyVehicle::MyVehicle() {

	glPushMatrix();
	positionInGL();
	RectangularPrism *box = new RectangularPrism(.5, 0.25, 0, 0, 2, 2, 0.5);
	box->setColor(0, 0, 1);
	addShape(box);
	TriangularPrism *tri = new TriangularPrism(0, .5, 0, 0, 1, .5, .7, 2);
	tri->setColor(0, 0, 1);
	addShape(tri);


	TrapezodialPrism *trap = new TrapezodialPrism(.5, .5, 0, 0, 2, 1, 1, .4, .5);
	trap->setColor(1, 1, 1);
	addShape(trap);
	Cylinder *flwheel = new Cylinder(0, .5, -1, 0, .5, .5);
	flwheel->setColor(0, 0, 0);
	addShape(flwheel);
	Cylinder *frwheel = new Cylinder(2, .5, -1, 0, .5, .5);
	frwheel->setColor(0, 0, 0);
	addShape(frwheel);
	Cylinder *blwheel = new Cylinder(0, .5, 1, 0, .5, .5);
	blwheel->setColor(0, 0, 0);
	addShape(blwheel);
	Cylinder *brwheel = new Cylinder(2, .5, 1, 0, .5, .5);
	brwheel->setColor(0, 0, 0);
	addShape(brwheel);
	// add a shape to see whether wheels are moving
	RectangularPrism *rect = new RectangularPrism(1, 0, 0.5, 0, 0.7, 2, 1);
	rect->setColor(0, 2, 1);
	addShape(rect);

	glPopMatrix();

};

MyVehicle::~MyVehicle(){

};

double MyVehicle::roll()
{
	double spin = 0;
	double it = 0;
	int i = 0;

	spin = spin + speed / 4;
	
	if (spin > 360) {
		spin = spin - 360;
	}

	if (spin < 0) {
		spin = spin + 360;
	}

	return spin;
}

/*
MyVehicle::MyVehicle(double x_, double y_, double z_, double rotation_) :Vehicle(x_, y_, z_ , rotation_)
{
	glPushMatrix();
	positionInGL();
	RectangularPrism *box = new RectangularPrism(.5, 0.25, 0, 0, 3, 2, .5);
	box->setColor(0, 0, 1);
	addShape(box);
	TriangularPrism *tri = new TriangularPrism(0, .5, 0, 0, 1, .5, .7, 2);
	tri->setColor(0, 0, 1);
	addShape(tri);
	TrapezodialPrism *trap = new TrapezodialPrism(.5, .5, 0, 0, 2, 1, 1, .4, .5);
	trap->setColor(1,1,1);
	addShape(trap);
	Cylinder *flwheel = new Cylinder(0,.5,-1,0,.5,.5);
	flwheel->setColor(0,0,0);
	addShape(flwheel);
	Cylinder *frwheel = new Cylinder(2, .5, -1, 0, .5, .5);
	frwheel->setColor(0, 0, 0);
	addShape(frwheel);
	Cylinder *blwheel = new Cylinder(0, .5, 1, 0, .5, .5);
	blwheel->setColor(0, 0, 0);
	addShape(blwheel);
	Cylinder *brwheel = new Cylinder(2, .5, 1, 0, .5, .5);
	brwheel->setColor(0, 0, 0);
	addShape(brwheel);

	glPopMatrix();
}
*/
void MyVehicle::draw()
{
	glPushMatrix();

	positionInGL();
	
	std::vector<Shape *>::iterator it;
	for (it = shapes.begin(); it != shapes.end(); it++) {
		// make the wheel steering
		if (it == shapes.begin() + 4 || it == shapes.begin() + 6) {
			(*it)->setRotation(steering);
		}
		
		// make the wheel rotated
		if (it > (shapes.begin() + 3) && it <= shapes.end()) {
			
			// might need to add gltranslate into rollingGL to move the rolling center 
			glPushMatrix();
			
			glRotated(-roll(), 0, 0, 1);
			(*it)->draw();
			glPopMatrix();
		}
		else {
			(*it)->draw();
		}
	
		//(*it)->draw();
	}


	glPopMatrix();
}
