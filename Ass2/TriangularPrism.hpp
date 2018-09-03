#pragma once


#include "Shape.hpp"
#include "math.h"

class TriangularPrism : public Shape
{

private:
	double base, side, theta, depth;

public:
	TriangularPrism(double x_, double y_, double z_, double rotation_, double base_, double side_, double theta_, double depth_);
	void draw();
};