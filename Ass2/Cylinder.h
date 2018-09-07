#pragma once
#include "shape.hpp"

class Cylinder : public Shape
{

private:
	

public:

	double radius, height;
	Cylinder(double x_, double y_, double z_, double rotation, double radius_, double height_);
	void draw();
	
};