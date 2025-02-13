#pragma once
#include "shape.hpp"

class Cylinder : public Shape
{

private:
	double spin;

public:

	double radius, height;
	Cylinder(double x_, double y_, double z_, double rotation, double radius_, double height_);
	void draw();
	void setSpin( double spin_);
	int front;
};