#include "Car.h"

int main2()
{
	Car run99 = { "run99",100,0 };
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.Break();
	run99.ShowCarState();

	return 0;
}