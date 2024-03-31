#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicle.h"
#include <cmath>

class Motorcycle : public Vehicle
{
public:
	Motorcycle(int x, int y, int w, int h, int id) : Vehicle(x,y,w,h, id) {}
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
		if (destinationY >= y1 - 10)
		{
			y1 = destinationY;
		}
		else
		y1 -= 12;

		//change x position
		if (abs(destinationX - x1) <= 11)
		{
			x1 = destinationX;
		}
		else if (x1 > destinationX)
		{
			x1 -= 15;
		}
		else
		x1 += 15;

		position(x1, y1);
	}

private:
};

#endif