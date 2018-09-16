#include "Custom.hpp"
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
#include <map>

CustomVehicle::CustomVehicle(VehicleModel *vm)
{	
	//iterator converts the shape init vector from the server VehicleModel into Vehicle Shape Vector
	std::vector<ShapeInit>::iterator it;
	for (it = vm->shapes.begin(); it != vm->shapes.end(); it++) {

		switch (it->type) {

			case RECTANGULAR_PRISM: 
			{
				RectangularPrism *rec = new RectangularPrism((double)it->xyz[0], (double)it->xyz[1], (double)it->xyz[2], it->rotation, it->params.rect.xlen, it->params.rect.ylen, it->params.rect.zlen);
				rec->setColor(it->rgb[0], it->rgb[1], it->rgb[2]);
				addShape(rec);
				continue;
			}

			case TRAPEZOIDAL_PRISM:
			{
				TrapezodialPrism *trap = new TrapezodialPrism((double)it->xyz[0], (double)it->xyz[1], (double)it->xyz[2], it->rotation, it->params.trap.alen, it->params.trap.blen, it->params.trap.height, it->params.trap.aoff, it->params.trap.depth);
				trap->setColor(it->rgb[0], it->rgb[1], it->rgb[2]);
				addShape(trap);
				continue;
			}


			case CYLINDER:
			{
				Cylinder *cyl = new Cylinder((double)it->xyz[0], (double)it->xyz[1], (double)it->xyz[2], it->rotation, it->params.cyl.radius, it->params.cyl.depth);
				cyl->setColor(it->rgb[0], it->rgb[1], it->rgb[2]);
				addShape(cyl);
				continue;
			}
			case TRIANGULAR_PRISM:
			{
				TriangularPrism *tri = new TriangularPrism((double)it->xyz[0], (double)it->xyz[1], (double)it->xyz[2], it->rotation, it->params.tri.alen, it->params.tri.blen, it->params.tri.angle, it->params.tri.depth);
				tri->setColor(it->rgb[0], it->rgb[1], it->rgb[2]);
				addShape(tri);
				continue;
			}
		}
	}
}


void CustomVehicle::draw()
{

	//draw function takes each shape indevidually and initiates its own draw function
	glPushMatrix();

	positionInGL();
	std::vector<Shape *>::iterator it;
	for (it = shapes.begin(); it != shapes.end(); it++) {
		(*it)->draw();
	}

	glPopMatrix();
}
