#pragma once

#include "Shape.hpp"


class RectangularPrism : public Shape {
	

public:
	double width, length, height;
	RectangularPrism(double x, double y, double z, double rotation_, double width, double length, double height);
	void draw();
	

};
