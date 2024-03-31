#ifndef SPORTS_H
#define SPORTS_H

#include "vehicle.h"
#include <cmath>

class Sports : public Vehicle
{
public:
	Sports(int x, int y, int w, int h, int id) : Vehicle(x, y, w, h, id) {}
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
		if (destinationY >= y1 - 20)
		{
			y1 = destinationY;
		}
		else
		{
			if (initialDrive)
			{
				y1 -= 22;
				initialDrive = false;
			}
			y1 -= 3;
		}

		//change x position
		if (abs(destinationX - x1) <= 15)
		{
			x1 = destinationX;
		}
		else
		{
		if (y1 - 100 < destinationY)
		{	
			if (x1 > destinationX)
			{
				x1 -= 15;
			}
		else
			x1 += 15;
		}
		else

		{
			if (leftTurn)
			{
				x1 -= 15;
				leftTurn = false;
			}
			else
			{
				x1 += 15;
				leftTurn = true;
			}
		}
	}

	position(x1, y1);
	}

private:
	double x1;
	double y1;
	bool initialDrive = true;
	bool leftTurn = true;
};

#endif