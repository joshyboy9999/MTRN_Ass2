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
Shape(x_, (y_+ radius), (z_ - height/2.0))
{
	x = x_;
	y = y_ + radius;
	z = z_ - (height/2.0);
	radius = radius_;
	height = height_;

}

void Cylinder::draw()
{
	//instanciate quadric ptr for cylinder body
	GLUquadric *cptr = gluNewQuadric();
	gluCylinder(cptr, radius, radius, height, 50, 50);

	

}

Disk::Disk(double x_, double y_, double z_, double radius_):Shape(x_, y_, z_)
{
	x = x_;
	y = y_;
	z = z_;
	radius = radius_;
}

void Disk::draw()
{
	GLUquadric *dptr = gluNewQuadric();
	gluDisk(dptr, 0, radius, 50, 50);
}
