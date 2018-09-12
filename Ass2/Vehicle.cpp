

#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezodialPrism.hpp"
#include "Cylinder.h"
#include "MyVehicle.hpp"
#include "Camera.hpp"
#include "Ground.hpp"
#include "KeyManager.hpp"

#include "Shape.hpp"
#include "Vehicle.hpp"

#include "RemoteDataManager.hpp"
#include "Messages.hpp"
#include "HUD.hpp"
#include "ObstacleManager.hpp"

Vehicle::Vehicle() {
	speed = steering = 0;
}



Vehicle::Vehicle(double x, double y,double  z, double rotation): Shape(x, y, z, rotation)
{

}
;

Vehicle::~Vehicle()
{ 
	// clean-up added shapes
	for(int i = 0; i < shapes.size(); i++) {
		delete shapes[i];
	}
}

void Vehicle::update(double dt)
{
	speed = clamp(MAX_BACKWARD_SPEED_MPS, speed, MAX_FORWARD_SPEED_MPS);
	steering = clamp(MAX_LEFT_STEERING_DEGS, steering, MAX_RIGHT_STEERING_DEGS);

	// update position by integrating the speed
	x += speed * dt * cos(rotation * 3.1415926535 / 180.0);
	z += speed * dt * sin(rotation * 3.1415926535 / 180.0);

	// update heading
	rotation += dt * steering * speed;

	while (rotation > 360) rotation -= 360;
	while (rotation < 0) rotation += 360;


	if(fabs(speed) < .1)
		speed = 0;
	if(fabs(steering) < .1)
		steering = 0;

}

void Vehicle::update(double speed_, double steering_, double dt) 
{
	speed = speed + ((speed_) - speed)*dt*4;
	steering = steering + (steering_ - steering)*dt * 6;

	update(dt);
}

void Vehicle::addShape(Shape * shape) 
{
	shapes.push_back(shape);
}

void Vehicle::populate(VehicleModel *vm)
{
	std::vector<Shape *>::iterator it;
	for (it = shapes.begin(); it != shapes.end(); it++) {
		ShapeInit shape;
		RectangularPrism *rec = dynamic_cast<RectangularPrism*>(*it);
		TriangularPrism  *tri = dynamic_cast<TriangularPrism*>(*it);
		TrapezodialPrism  *tra = dynamic_cast<TrapezodialPrism*>(*it);
		Cylinder *cyl = dynamic_cast<Cylinder*>(*it);

		if (rec != nullptr) {
			shape.type = RECTANGULAR_PRISM;

			shape.params.rect.xlen = rec->length;
			shape.params.rect.ylen = rec->height;
			shape.params.rect.zlen = rec->width;
			shape.xyz[0] = rec->getX();
			shape.xyz[1] = rec->getY();
			shape.xyz[2] = rec->getZ();
			shape.rotation = rec->getRotation();
			shape.rgb[0] = rec->getRed();
			shape.rgb[1] = rec->getGreen();
			shape.rgb[2] = rec->getBlue();
		}


		if (tri != nullptr) {
			shape.type = TRIANGULAR_PRISM;

			shape.params.tri.alen = tri->base;
			shape.params.tri.blen = tri->side;
			shape.params.tri.angle = tri->theta;
			shape.params.tri.depth = tri->depth;
			shape.xyz[0] = tri->getX();
			shape.xyz[1] = tri->getY();
			shape.xyz[2] = tri->getZ();
			shape.rotation = tri->getRotation();
			shape.rgb[0] = tri->getRed();
			shape.rgb[1] = tri->getGreen();
			shape.rgb[2] = tri->getBlue();
		}

		if (tra != nullptr) {
			shape.type = TRAPEZOIDAL_PRISM;

			shape.params.trap.alen = tra->base_length;
			shape.params.trap.blen = tra->top_length;
			shape.params.trap.aoff = tra->a_offset;
			shape.params.trap.height = tra->height;
			shape.params.trap.depth = tra->depth;
			shape.xyz[0] = tra->getX();
			shape.xyz[1] = tra->getY();
			shape.xyz[2] = tra->getZ();
			shape.rotation = tra->getRotation();
			shape.rgb[0] = tra->getRed();
			shape.rgb[1] = tra->getGreen();
			shape.rgb[2] = tra->getBlue();
		}

		if (cyl != nullptr) {
			shape.type = CYLINDER;

			shape.params.cyl.radius = cyl->radius;
			shape.params.cyl.depth = cyl->height;
			shape.params.cyl.isRolling = (abs(getSpeed()) > 0);
			shape.params.cyl.isSteering = (abs(getSteering()) > 0);
			shape.xyz[0] = cyl->getX();
			shape.xyz[1] = cyl->getY();
			shape.xyz[2] = cyl->getZ();
			shape.rotation = cyl->getRotation();
			shape.rgb[0] = cyl->getRed();
			shape.rgb[1] = cyl->getGreen();
			shape.rgb[2] = cyl->getBlue();

		}


		vm->shapes.push_back(shape);
	}

}

double clamp(double a, double n, double b) {

	if (a < b) {
		if (n < a) n = a;
		if (n > b) n = b;
	} else {
		if (n < b) n = b;
		if (n > a) n = a;
	}

	return n;

};

