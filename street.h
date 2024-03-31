#include <string>
#include <vector>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>
using namespace std;

const int W_WIDTH = 600;
const int W_HEIGHT = 400;
const int CARS = 10;

class Street : public Fl_Double_Window
{
public:
	Street(int width, int height);

	virtual void draw();
	//This causes compiler to create a virtual function
	//table which is an array of function pointers
	//At runtime, the RTTI (RunTime Type Information) is
	//used to figured out which of the pointers in
	//the array to call based on type of object that
	//invoked it.

	int getStreet_Y();
	//maybe boolean to stop moving if there is another car
	double getParkingLocationX(int carNumber);
	int getNumberOfParkingCars();
private:
	vector<double> parkingCarsLocation;
	int street_x;
	int street_y;
	int street_w;
	int street_h;
};