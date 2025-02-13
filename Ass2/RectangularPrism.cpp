#include "RectangularPrism.hpp"

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

//instanciates new rectangle shape 
RectangularPrism::RectangularPrism(double x_, double y_, double z_,double rotation_, double width_, double length_, double height_)
	: Shape(x_, y_, z_, rotation_) {
		
		width = width_;
		length = length_;
		height = height_;
}

void RectangularPrism::draw()
{
	double half_width = width / 2.0;
	length = length / 2.0;
	double half_height = height / 2.0;
	glPushMatrix();
	positionInGL();
	setColorInGL();
	//make 2 faces, make all the sides linking the faces

	//first make 2 faces with displacement = length
	glBegin(GL_QUADS);
		glVertex3d(x + half_width, y + height, z + length); //first corner at start
		glVertex3d(x - half_width, y + height, z + length);
		glVertex3d(x - half_width, y + height, z - length);
		glVertex3d(x + half_width, y + height, z - length);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3d(x +  half_width, y, z + length); //bottom face
		glVertex3d(x - half_width, y, z + length);
		glVertex3d(x - half_width, y, z - length);
		glVertex3d(x + half_width, y, z - length);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3d(x - half_width, y, z - length); //left face
		glVertex3d(x - half_width, y, z + length);
		glVertex3d(x - half_width, y + height, z + length);
		glVertex3d(x - half_width, y + height, z - length);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3d(x + half_width, y, z - length); //right face
		glVertex3d(x + half_width, y, z + length);
		glVertex3d(x + half_width, y + height, z + length);
		glVertex3d(x + half_width, y + height, z - length);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3d(x - half_width, y + height, z - length); //front face
		glVertex3d(x - half_width, y, z - length);
		glVertex3d(x + half_width, y, z - length);
		glVertex3d(x + half_width, y + height, z - length);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3d(x - half_width, y + height, z + length); //back face
		glVertex3d(x - half_width, y, z + length);
		glVertex3d(x + half_width, y, z + length);
		glVertex3d(x + half_width, y + height, z + length);
	glEnd();

	glPopMatrix();
}
