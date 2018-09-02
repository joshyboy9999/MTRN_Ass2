#include "MyVehicle.hpp"
#include "Vehicle.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "Cylinder.h"
#include "TrapezodialPrism.hpp"

MyVehicle::MyVehicle():Vehicle()
{
}

void MyVehicle::draw()
{
	RectangularPrism box(0, 20, 0, 20, 40, 20);
	TriangularPrism tri(10, 20, 0, 20, 20, 0.5, 10);
	TrapezodialPrism trap(0, 40, 0, 10, 3, 4, 1, 20);
	//Cylinder()
	tri.draw();
	box.draw();
	trap.draw();
}
