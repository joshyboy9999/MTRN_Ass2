
#include "Vehicle.hpp"

class MyVehicle : public Vehicle {
	
public:
	MyVehicle();
	~MyVehicle();
	//MyVehicle(double x_, double y_, double z_, double rotation_);
	double roll();
	void draw();
private:
	double spin = 0;

};