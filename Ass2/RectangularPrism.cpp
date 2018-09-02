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

RectangularPrism::RectangularPrism(double x_, double y_, double z_, double width_, double length_, double height_)
	: Shape(x_, y_, z_) {
		blue = .5;
		green = .5;

		width = width_;
		length = length_;
		height = height_;
}

void RectangularPrism::draw()
{
	double half_width = length / 2;
	length = length / 2;
	double half_height = height / 2;

	float rectangular_vertices[] =
	{
		// Top 
		x + half_width, y + height, z + length,
		x - half_width, y + height, z + length,
		x - half_width, y + height, z - length,
		x + half_width, y + height, z - length,
		// left
		x - half_width, y + height, z + length,
		x - half_width, y + height, z - length,
		x - half_width, y  , z + length,
		x - half_width, y  , z - length,
		// right
		x + half_width, y + height, z + length,
		x + half_width, y + height, z - length,
		x + half_width, y, z + length,
		x + half_width, y, z - length,
		// bottom
		x + half_width, y, z + length,
		x + half_width, y , z - length,
		x - half_width, y , z + length,
		x - half_width, y , z - length,
		// front
		x + half_width, y + half_height, z - length,
		x + half_width, y , z - length,
		x - half_width, y + half_height, z - length,
		x - half_width, y , z - length,
		// back
		x + half_width, y + half_height, z + length,
		x + half_width, y, z + length,
		x - half_width, y + half_height, z + length,
		x - half_width, y, z + length

	};

	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer(3, GL_FLOAT, 0, rectangular_vertices);
	glDrawArrays(GL_QUADS, 0, 24);
	glDisableClientState(GL_VERTEX_ARRAY);

}
