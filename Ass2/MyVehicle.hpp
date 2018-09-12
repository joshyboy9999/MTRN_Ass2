
#include "Vehicle.hpp"
#include "Messages.hpp"

class MyVehicle : public Vehicle {
	
public:
	MyVehicle();
	~MyVehicle();
	//MyVehicle(double x_, double y_, double z_, double rotation_);
	MyVehicle( VehicleModel *vm);
	void draw();
	double roll();
	VehicleModel setLocal();

private:
	double spin;
	ShapeInit *local;
	ShapeInit *Remote;
};