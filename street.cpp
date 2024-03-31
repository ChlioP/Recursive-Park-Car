#include "street.h"

#include <string>
#include <ctime>
#include <vector>

using namespace std;
//helper function prototype
double fRand(double fMin, double fMax);
string parkingSequence(double streetLeft, double streetRight);
static void Timer_CB(void *parkingCars);

Street::Street(int width, int height)
: Fl_Double_Window(width, height), parkingCarsLocation(),street_x(45), street_y(130), street_w(400), street_h(2)
{
	string parkingSpaces = parkingSequence(0.5, 9.5);
	string delimiter = " ";
	int counter = 0;
	while ((counter = parkingSpaces.find(delimiter)) != string::npos)
	{

		string a = parkingSpaces.substr(0, counter);
		parkingCarsLocation.push_back(stod(a));
		parkingSpaces.erase(0, counter + delimiter.length());
	}
	if (parkingSpaces.length() > 0)
	{
		parkingCarsLocation.push_back(stod(parkingSpaces));
	}
}

void Street::draw()
{
	Fl_Double_Window::draw();
	int x, y;
	//display title
	fl_color(FL_BLUE);
	fl_font(FL_ITALIC, 16);
	std::string s = "Recursive Car Park";
	x = 1 * W_WIDTH / 8;
	y = 1 * W_HEIGHT / 5;
	fl_draw(s.c_str(), x, y);
	//display street

	fl_color(FL_DARK_YELLOW);
	fl_rectf(street_x, street_y + 20, street_w, street_h);
}

int Street::getStreet_Y()
{
	return street_y;

}

double Street::getParkingLocationX(int carNumber)
{
	return parkingCarsLocation[carNumber] / CARS * street_w;
}

int Street::getNumberOfParkingCars()
{
	return parkingCarsLocation.size();
}

//recursive helper function
string parkingSequence(double streetLeft, double streetRight)
{
	string carPos = ""; //to store the midpoint of where a car park
	if (streetRight - streetLeft <= 0)
	{
		return carPos;
	}
	else
	{
		double streetLeft2, streetRight2;
		double parkWhere = fRand(streetLeft, streetRight);
		carPos = to_string(parkWhere);
		streetLeft2 = parkWhere + 1;
		streetRight2 = parkWhere - 1;

		string result_left = parkingSequence(streetLeft, streetRight2);
		string result_right = parkingSequence(streetLeft2, streetRight);
		if (result_left.length() > 0)
		{
			carPos = result_left + " " + carPos;
		}
		if (result_right.length() > 0)
		{
			carPos = carPos + " " + result_right;
		}

		return carPos;
	}
}
//to generate a random number in a certain range
double fRand(double fMin, double fMax)
{
	srand(time(NULL));
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}