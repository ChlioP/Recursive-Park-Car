#ifndef SEDAN_H
#define SEDAN_H

#include "vehicle.h"
#include <cmath>

class Sedan : public Vehicle
{
public:
	Sedan(int x, int y, int w, int h, int id) : Vehicle(x, y, w, h, id) {}
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
				y1 -= 2;
		}
		//change x position
		if (abs(destinationX - x1) <= 4)
		{
			x1 = destinationX;
		}
		else if (x1 > destinationX)
		{
			x1 -= 7;
		}
		else
		x1 += 7;

		position(x1, y1);
	}

private:
	bool initialDrive = true;
};
#endif