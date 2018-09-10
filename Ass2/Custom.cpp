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

CustomVehicle::CustomVehicle()
{

}

void CustomVehicle::draw()
{
	glPushMatrix();

	positionInGL();
	std::vector<Shape *>::iterator it;
	for (it = shapes.begin(); it != shapes.end(); it++) {
		(*it)->draw();
	}

	glPopMatrix();
}
