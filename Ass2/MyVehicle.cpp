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

//instanciating a new version of my vehicle
MyVehicle::MyVehicle() {

	//creating new instance of each shape and arranging them correctly in the vehicle
	//push each shape to vector of shapes contained within vehicle class
	glPushMatrix();
	positionInGL();
	RectangularPrism *box = new RectangularPrism(.5, 0.25, 0, 0, 3, 2, .5);
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
	flwheel->front = 0;
	addShape(flwheel);

	Cylinder *frwheel = new Cylinder(2, .5, -1, 0, .5, .5);
	frwheel->setColor(0, 0, 0);
	frwheel->front = 1;
	addShape(frwheel);

	Cylinder *blwheel = new Cylinder(0, .5, 1, 0, .5, .5);
	blwheel->setColor(0, 0, 0); 
	blwheel->front = 0;
	addShape(blwheel);

	Cylinder *brwheel = new Cylinder(2, .5, 1, 0, .5, .5);
	brwheel->setColor(0, 0, 0);
	brwheel->front = 1;
	addShape(brwheel);
	

	glPopMatrix();
};

//default destructor
MyVehicle::~MyVehicle(){

};

//MyVehicle Method used to set the rolling speed of the wheels based on speed from vehicle state
double MyVehicle::roll()
{
	int i = 0;

	spin =  spin + speed * 10/ (3.14 * 3.14);
	
	if (spin > 360) {
		spin = spin - 360;
	}

	if (spin < 0) {
		spin = spin + 360;
	}

	return spin;
}

//MyVehicle method used to populate a vm to be sent to the server
VehicleModel MyVehicle::setLocal(VehicleModel *vm)
{
	
	//each shape of the vehicle is packaged to a shape init pointer and added to the shapes vector
	ShapeInit *box = new ShapeInit;
	box->type = RECTANGULAR_PRISM;
	box->params.rect.xlen = 3;
	box->params.rect.ylen = 2;
	box->params.rect.zlen = .5;
	box->xyz[0] = .5;
	box->xyz[1] = .25;
	box->xyz[2] = 0;
	box->rotation = 0;
	box->rgb[0] = 0;
	box->rgb[1] = 0;
	box->rgb[2] = 1;
	vm->shapes.push_back(*box);

	ShapeInit *tri = new ShapeInit;
	tri->type = TRIANGULAR_PRISM;
	tri->params.tri.alen =1;
	tri->params.tri.blen = .5;
	tri->params.tri.angle = .7;
	tri->params.tri.depth = 2;
	tri->xyz[0] = 0;
	tri->xyz[1] = .5;
	tri->xyz[2] = 0;
	tri->rotation = 0;
	tri->rgb[0] = 0;
	tri->rgb[1] = 0;
	tri->rgb[2] = 1;
	vm->shapes.push_back(*tri);

	ShapeInit *trap1 = new ShapeInit;
	trap1->type = TRAPEZOIDAL_PRISM;
	trap1->params.trap.alen = 2;
	trap1->params.trap.blen = 1;
	trap1->params.trap.aoff = .4;
	trap1->params.trap.height = 1;
	trap1->params.trap.depth = .5;
	trap1->xyz[0] = .5;
	trap1->xyz[1] = .5;
	trap1->xyz[2] = 0;
	trap1->rotation = 0;
	trap1->rgb[0] = 1;
	trap1->rgb[1] = 1;
	trap1->rgb[2] = 1;
	vm->shapes.push_back(*trap1);

	ShapeInit *flwheel = new ShapeInit;
	flwheel->type = CYLINDER;
	flwheel->params.cyl.radius = .5;
	flwheel->params.cyl.depth = .5;
	flwheel->params.cyl.isRolling =  1;
	flwheel->params.cyl.isSteering = 0;
	flwheel->xyz[0] = 0;
	flwheel->xyz[1] = .5;
	flwheel->xyz[2] = -1;
	flwheel->rotation =0;
	flwheel->rgb[0] = 0;
	flwheel->rgb[1] = 0;
	flwheel->rgb[2] = 0;
	vm->shapes.push_back(*flwheel);

	ShapeInit *frwheel = new ShapeInit;
	frwheel->type = CYLINDER;
	frwheel->params.cyl.radius = .5;
	frwheel->params.cyl.depth = .5;
	frwheel->params.cyl.isRolling = 1;
	frwheel->params.cyl.isSteering = 1;
	frwheel->xyz[0] = 2;
	frwheel->xyz[1] = .5;
	frwheel->xyz[2] = -1;
	frwheel->rotation = 0;
	frwheel->rgb[0] = 0;
	frwheel->rgb[1] = 0;
	frwheel->rgb[2] = 0;
	vm->shapes.push_back(*frwheel);

	ShapeInit *blwheel = new ShapeInit;
	blwheel->type = CYLINDER;
	blwheel->params.cyl.radius = .5;
	blwheel->params.cyl.depth = .5;
	blwheel->params.cyl.isRolling = 1;
	blwheel->params.cyl.isSteering = 0;
	blwheel->xyz[0] = 0;
	blwheel->xyz[1] = .5;
	blwheel->xyz[2] = 1;
	blwheel->rotation = 0;
	blwheel->rgb[0] = 0;
	blwheel->rgb[1] = 0;
	blwheel->rgb[2] = 0;
	vm->shapes.push_back(*blwheel);

	ShapeInit *brwheel = new ShapeInit;
	brwheel->type = CYLINDER;
	brwheel->params.cyl.radius = .5;
	brwheel->params.cyl.depth = .5;
	brwheel->params.cyl.isRolling = 1;
	brwheel->params.cyl.isSteering = 1;
	brwheel->xyz[0] = 2;
	brwheel->xyz[1] = .5;
	brwheel->xyz[2] = 1;
	brwheel->rotation = 0;
	brwheel->rgb[0] = 0;
	brwheel->rgb[1] = 0;
	brwheel->rgb[2] = 0;
	vm->shapes.push_back(*brwheel);

	return *vm;
}


//method used to parse a vehicle model from the server into the local client by changing from shape init to shape pointers
MyVehicle::MyVehicle(VehicleModel * vm)
{
	std::vector<ShapeInit>::iterator it;
	for (it = vm->shapes.begin(); it != vm->shapes.end(); it++) {

		switch (it->type) {

		case RECTANGULAR_PRISM: {
			Shape *rec = new RectangularPrism((double)it->xyz[0], (double)it->xyz[1], (double)it->xyz[2], it->rotation, it->params.rect.xlen, it->params.rect.ylen, it->params.rect.zlen);
			rec->setColor(it->rgb[0], it->rgb[1], it->rgb[2]);
			addShape(rec);
			break;
		}

		case TRAPEZOIDAL_PRISM:
		{
			Shape *trap = new TrapezodialPrism((double)it->xyz[0], (double)it->xyz[1], (double)it->xyz[2], it->rotation, it->params.trap.alen, it->params.trap.blen, it->params.trap.height, it->params.trap.aoff, it->params.trap.depth);
			trap->setColor(it->rgb[0], it->rgb[1], it->rgb[2]);
			addShape(trap);
			break;
		}


		case CYLINDER:
		{
			Shape *cyl = new Cylinder((double)it->xyz[0], (double)it->xyz[1], (double)it->xyz[2], it->rotation, it->params.cyl.radius, it->params.cyl.depth);
			cyl->setColor(it->rgb[0], it->rgb[1], it->rgb[2]);
			addShape(cyl);
			break;
		}
		case TRIANGULAR_PRISM:
		{
			Shape *tri = new TriangularPrism((double)it->xyz[0], (double)it->xyz[1], (double)it->xyz[2], it->rotation, it->params.tri.alen, it->params.tri.blen, it->params.tri.angle, it->params.tri.depth);
			tri->setColor(it->rgb[0], it->rgb[1], it->rgb[2]);
			addShape(tri);
			break;
		}

		}


	}
}

void MyVehicle::draw()
{
	glPushMatrix();
	positionInGL();
	
	std::vector<Shape *>::iterator it;
	for (it = shapes.begin(); it != shapes.end(); it++) {
		
		//create cylinder pointer for later manipulation in steering and spinning
		Cylinder * ptr = dynamic_cast<Cylinder *>(*it);
		
		// make the wheel rotated
		if ( ptr !=  nullptr) {

			//sets wheels positioned at the front of the vehicle to be steered depending on the direction
			if(ptr->front == 1) (*it)->setRotation(getSteering());
			roll();
			if (ptr != nullptr) ptr->setSpin(spin);
		}
		
		(*it)->draw();
	}


	glPopMatrix();
}
