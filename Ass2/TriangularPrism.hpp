#pragma once


#include "Shape.hpp"
#include "math.h"

class TriangularPrism : public Shape
{

public:
	TriangularPrism(double x_, double y_, double z_, double rotation_, double base_, double side_, double theta_, double depth_);

	void draw();

	double base, side, theta, depth;
};