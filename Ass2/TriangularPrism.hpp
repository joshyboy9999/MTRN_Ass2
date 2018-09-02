#pragma once


#include "Shape.hpp"
# include "math.h"

class TriangularPrism : public Shape
{

private:
	double base, side, theta, depth;

public:
	TriangularPrism(double x, double y, double z, double base, double side,double theta, double depth);
	void draw();
};