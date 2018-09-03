#pragma once


#include "Shape.hpp"
# include "math.h"

class TrapezodialPrism : public Shape
{

private:
	double base_length, top_length, height, a_offset, b_offset, depth;

public:
	TrapezodialPrism(double x_, double y_, double z_, double rotation_, double base_length_, double top_length_, double height_, double a_offset_, double depth_);
	void draw();
};