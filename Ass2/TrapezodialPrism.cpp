#include "TrapezodialPrism.hpp"
 
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


TrapezodialPrism::TrapezodialPrism(double x_, double y_, double z_, double rotation_, double base_length_, double top_length_, double height_, double a_offset_, double depth_)
	: Shape(x_, y_, z_, rotation_) {


	base_length = base_length_;
	top_length = top_length_;
	height = height_;
	a_offset = a_offset_;
	b_offset = a_offset;
	depth = depth_;
}

void TrapezodialPrism::draw()
{
	double half_base = base_length / 2.0;
	double half_depth = depth / 2.0;
	
	glPushMatrix();
	positionInGL();
	setColorInGL();
	// Top
	glBegin(GL_QUADS);
		glVertex3f(x + half_base - b_offset, y + height, z + half_depth);
		glVertex3f(x + half_base - b_offset, y + height, z - half_depth);
		glVertex3f(x - half_base + a_offset, y + height, z - half_depth);
		glVertex3f(x - half_base + a_offset, y + height, z + half_depth);
	glEnd();
	
	// Bottom
	glBegin(GL_QUADS);
		glVertex3f(x + half_base, y, z - half_depth);
		glVertex3f(x + half_base, y, z + half_depth);
		glVertex3f(x - half_base, y, z + half_depth);
		glVertex3f(x - half_base, y, z - half_depth);
	glEnd();
	
	// Left 
	glBegin(GL_QUADS);
		glVertex3f(x - half_base, y, z + half_depth);
		glVertex3f(x - half_base, y, z - half_depth);
		glVertex3f(x - half_base + a_offset, y + height, z - half_depth);
		glVertex3f(x - half_base + a_offset, y + height, z + half_depth);
	glEnd();

	// Right
	glBegin(GL_QUADS);
		glVertex3f(x + half_base, y, z + half_depth);
		glVertex3f(x + half_base, y, z - half_depth);
		glVertex3f(x + half_base - b_offset, y + height, z - half_depth);
		glVertex3f(x + half_base - b_offset, y + height, z + half_depth);
	glEnd();
	
	// Front
	glBegin(GL_QUADS);
		glVertex3f(x + half_base, y, z - half_depth);
		glVertex3f(x + half_base - b_offset, y + height, z - half_depth);
		glVertex3f(x - half_base + a_offset, y + height, z - half_depth);
		glVertex3f(x - half_base, y, z - half_depth);
	glEnd();

	// Back
	glBegin(GL_QUADS);
		glVertex3f(x + half_base, y, z + half_depth);
		glVertex3f(x + half_base - b_offset, y + height, z + half_depth);
		glVertex3f(x - half_base + a_offset, y + height, z + half_depth);
		glVertex3f(x - half_base, y, z + half_depth);
	glEnd();

	glPopMatrix();
	
}
