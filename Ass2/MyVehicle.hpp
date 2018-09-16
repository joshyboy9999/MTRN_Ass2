
#include "Vehicle.hpp"
#include "Messages.hpp"

class MyVehicle : public Vehicle {
	
public:
	MyVehicle();
	MyVehicle(VehicleModel *vm);

	~MyVehicle();
	

	void draw();
	double roll();

	VehicleModel setLocal(VehicleModel *vm);

private:
	double spin;
	ShapeInit *local;
	ShapeInit *Remote;
};