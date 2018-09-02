#include "MyVehicle.hpp"
#include "Vehicle.hpp"
#include "RectangularPrism.hpp"
#include "Cylinder.h"
#include "TrapezodialPrism.hpp"

MyVehicle::MyVehicle():Vehicle()
{

}

void MyVehicle::draw()
{
	RectangularPrism box(0, 20, 0, 20, 40, 20);
	TrapezodialPrism trap(0, 40, 0, 10, 3, 4, 1, 20);
	//Cylinder()

}
