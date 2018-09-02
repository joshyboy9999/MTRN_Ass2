#include "Cylinder.h"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <unistd.h>
#include <sys/time.h>
#elif defined(WIN32)
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <sys/time.h>
#endif



Cylinder::Cylinder(double x_, double y_, double z_, double radius_, double height_):
Shape(x_, y_, z_)
{
	x = x_;
	y = y_;
	z = z_;
	radius = radius_;
	height = height_;

}

void Cylinder::draw()
{
	double half_height = height / 2;
	// move to z, y, z
	// Draw the cylinder
	glTranslated(x, y, z);
	GLUquadric *cptr = gluNewQuadric();
	gluCylinder(cptr, radius, radius, height, 50, 20);
	

	// Draw the circle
	// instantiate the two circles
	GLUquadric *disk_front = gluNewQuadric();
	GLUquadric *disk_back = gluNewQuadric();
	// draw front disk
	gluDisk(disk_front, 0, radius, 50, 1);
	// move frontward by one height
	glTranslated(0, 0, half_height);
	// draw the second disk
	gluDisk(disk_back, 0, radius, 50, 1);
	
}
