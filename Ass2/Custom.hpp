#include "Vehicle.hpp"
#include "Messages.hpp"
#include <map>

class CustomVehicle : public Vehicle
{
public:
	CustomVehicle();
	CustomVehicle(VehicleModel *vm);
	void draw();

private:

};
