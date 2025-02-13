#include "TriangularPrism.hpp"


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




//instanciates new triangular prism
TriangularPrism::TriangularPrism(double x_, double y_, double z_,double rotation_, double base_, double side_, double theta_, double depth_)
	: Shape(x_, y_, z_, rotation_) {


	base = base_;
	side = side_;
	depth = depth_;
	theta = theta_;
}


//draws new triangular prism to the client
void TriangularPrism::draw()
{
	double half_depth = depth / 2.0;
	double half_base = base / 2.0;
	double height = sin(theta) * side;
	double cos_length = cos(theta) * side;
	
	glPushMatrix();
	positionInGL();
	setColorInGL();
	// Top
	glBegin( GL_QUADS );
		glVertex3f(x + half_base, y , z + half_depth);
		glVertex3f(x + half_base, y , z - half_depth);
		glVertex3f(x - half_base + cos_length, y + height, z - half_depth);
		glVertex3f(x - half_base + cos_length, y + height, z + half_depth);
	glEnd();
	
	// Bottom
	glBegin( GL_QUADS );
		glVertex3f(x + half_base, y, z + half_depth);
		glVertex3f(x + half_base, y, z - half_depth);
		glVertex3f(x- half_base, y, z - half_depth);
		glVertex3f(x - half_base , y , z + half_depth);
	glEnd();
	
	// Front
	glBegin( GL_TRIANGLES );
		glVertex3f(x + half_base, y, z - half_depth);
		glVertex3f(x - half_base, y, z - half_depth);
		glVertex3f(x - half_base + cos_length, y + height, z - half_depth);
	glEnd();
	
	// Back
	glBegin(GL_TRIANGLES );
		glVertex3f(x + half_base, y, z + half_depth);
		glVertex3f(x - half_base, y, z + half_depth);
		glVertex3f(x - half_base + cos_length, y + height, z + half_depth);
	glEnd();
	
	// Side
	glBegin(GL_QUADS);
		glVertex3f(x - half_base, y, z - half_depth);
		glVertex3f(x - half_base + cos_length, y + height, z - half_depth);
		glVertex3f(x - half_base + cos_length, y, z + half_depth);
		glVertex3f(x - half_base, y, z + half_depth);
	glEnd();

	glPopMatrix();
	
}
