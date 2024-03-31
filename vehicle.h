#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
using namespace std;

class Vehicle : public Fl_Box
{
public:
	Vehicle(int x, int y, int w, int h, int id) : Fl_Box(x,y,w,h),
	parked(false), id('A') {}
	//use x() and y() to get x and y
	virtual void drive(double destinationX, double destinationY)
	{
		//changing position of cars
		//when car parked update the
		//parked to true
		int x1 = x();
		int y1 = y();
		y1-=2;
		position(x1,y1);
		parked = true;
	}
	bool isParked()
	{
		//accessor
		return parked;
	}
	void setParked(bool new_parked) {
	//mutator
	parked = new_parked;
	}
	void draw()
	{
		Fl_Box::draw();
	}
	void printLocation() 
	{
		cout << "(" << x() << ", "<< y() << ")" << endl;
	}
private:
	bool parked;
	char id;
	int spaceX;
	int spaceY;
};


#endif