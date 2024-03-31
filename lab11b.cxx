#include <string>
#include <time.h>
#include "lab11b.h"
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
Vehicle *cars[CARS];
vector<int> *carSelections;
int programRunTimes = 0;

void reset_all_car_position()
{
	for (int i = 0; i < CARS; i++)
	{
		cars[i]->position(i * CARWIDTH + 50, 308);
		cars[i]->setParked(false);
	}
}
//randomly selected cars number from garage
void randomlyPick(int numberOfCarsParking)
{
	unordered_set<int> selectedCars;
	srand(time(NULL));
	while (selectedCars.size() < numberOfCarsParking)
	{
		selectedCars.insert(random() % 10);
	}
	carSelections = new vector<int>(selectedCars.begin(), selectedCars.end());

}

void drive_cb(void *w)
{
	static int i = 0;
	Street *street = (Street *) w;

	int numOfCarsParking = street->getNumberOfParkingCars();

	cars[(*carSelections)[i]]->drive(street->getParkingLocationX(i)-10, street->getStreet_Y()+ 20);

	if (cars[(*carSelections)[i]]->isParked())
	{
		i = (i + 1) % CARS;  // park next car
	}
	//let program runs three times
	if (programRunTimes == 3)
	{
		//reset cars
		Fl::remove_timeout(drive_cb, w);
		return;
	}
	//terminate timer

	if (i == numOfCarsParking)
	{
	//let program run three times
	//otherwise reset the cars position and i
		reset_all_car_position();
		randomlyPick(numOfCarsParking);
		i = 0;
		programRunTimes++;
	}
	street->redraw();

	Fl::repeat_timeout(0.1, drive_cb, w);
}

int main()
{
	cout << "Program Start" << endl;
	Street *w = new Street(530, 355);
	cout << "Successfully created Street" << endl;
	//make window white
	w->color((Fl_Color)55);
	
	//picking cars for parking
	randomlyPick(w->getNumberOfParkingCars());
	
	//loop 10 times and created diffenet types of cars
	for (int i = 0; i < CARS; i++)
	{
		switch (i)
		{
		case 0:
		case 1:
		case 2:
		case 4:
		case 6:
			cars[i] = new Sedan(i * CARWIDTH + 50, 308, CARWIDTH, CARHEIGHT, i);
			break;
		case 3:
		case 7:
		case 9:
			cars[i] = new Sports(i * CARWIDTH + 50, 308, CARWIDTH, CARHEIGHT, i);
			break;
		case 5:
			cars[i] = new Motorcycle(i * CARWIDTH + 50, 308, CARWIDTH, CARHEIGHT, i);
			break;
		case 8:
			cars[i] = new Truck(i * CARWIDTH + 50, 308, CARWIDTH, CARHEIGHT, i);
			break;
		}

	cars[i]->box(FL_UP_FRAME);
	string imageFile = "car" + to_string(i) + ".png";
	cars[i]->image(new Fl_PNG_Image(imageFile.c_str()));

	}
w->end();

w->show();



Fl::add_timeout(0.1, drive_cb, w);
return Fl::run();
}