#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"
#include <cmath>

class Truck : public Vehicle
{
public:
	Truck(int x, int y, int w, int h, int id) : Vehicle(x, y, w, h, id) {}

	void drive(double destinationX, double destinationY)
	{
		int x1 = x();			
		int y1 = y();
		if (y1 == static_cast<int>(destinationY) && x1 == static_cast<int>(destinationX))
		{
			setParked(true);
			return;
		}
		//change y position
		if (destinationY >= y1 - 6)
		{
			y1 = destinationY;
		}		
		else
		{
			if (initialDrive)
			{
				y1 -= 20;
				initialDrive = false;
			}
			y1 -= 5;
		}

		//change x position
		if (abs(destinationX - x1) <= 6)
		{
			x1 = destinationX;
		}
		else if (x1 > destinationX)
		{
			x1 -= 5;
		}
		else
			x1 += 5;

	position(x1, y1);
	}

private:

	double x1;
	double y1;
	bool initialDrive = true;
};

#endif