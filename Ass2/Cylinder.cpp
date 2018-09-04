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



Cylinder::Cylinder(double x_, double y_, double z_,double rotation, double radius_, double height_):
Shape(x_, y_, z_, rotation)
{
	radius = radius_;
	height = height_;

}

void Cylinder::draw()
{
	double half_height = height / 2.0;
	GLUquadric *cptr = gluNewQuadric();
	GLUquadric *disk_front = gluNewQuadric();
	GLUquadric *disk_back = gluNewQuadric();
	// Draw the cylinder
	glPushMatrix();
	positionInGL();

	glPushMatrix();
	glTranslated(0, 0, -half_height);

	gluCylinder(cptr, radius, radius, height, 50, 50);
	
	//draw ends of cylinder
	gluDisk(disk_front, 0, radius, 50, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, half_height);
	gluDisk(disk_back, 0, radius, 50, 1);
	glPopMatrix();

	glPopMatrix();
}
