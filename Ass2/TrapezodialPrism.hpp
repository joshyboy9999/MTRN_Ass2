#pragma once


#include "Shape.hpp"
# include "math.h"

class TrapezodialPrism : public Shape
{

private:
	double base_length, top_length, height, a_offset, b_offset, depth;

public:
	TrapezodialPrism(double x, double y, double z, double base_length, double top_length, double height, double a_offset, double depth);
	void draw();
};