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



Cylinder::Cylinder(double x_, double y_, double z_, double radius, double height):
Shape(x_, y_, z_)
{
	GLUquadric* cptr = gluNewQuadric();
	x = x_;
	y = y_;
	z = z_;
}
