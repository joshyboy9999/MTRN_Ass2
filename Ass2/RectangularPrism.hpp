#pragma once

#include "Shape.hpp"


class RectangularPrism : public Shape {

private:
	double width, length, height;

public:
	RectangularPrism(double x, double y, double z,double width, double length, double height);
	void draw();
	

};
