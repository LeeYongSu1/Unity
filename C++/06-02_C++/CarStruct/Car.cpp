#include "Car.h"
#include "Default.h"

void Car::ShowCarState()
{
	cout << "¼ÒÀ¯ÀÚ ID: " << gamerID << endl;
	cout << "¿¬·á·®: " << fuleGauge << endl;
	cout << "ÇöÀç¼Óµµ: " << curSpeed << endl;
}
void Car::Accel()
{
	if (fuleGauge <= 0)
	{
		return;
	}

	else
		fuleGauge -= FUEL_STEP;

	if (curSpeed + ACC_STEP >= MAX_SPD)
	{
		curSpeed = MAX_SPD;
		return;
	}
	curSpeed += ACC_STEP;
	cout << "ºÎ¿õ~" << endl;
}
void Car::Break()
{
	if (curSpeed < BRK_STEP)
	{
		curSpeed = 0;
		cout << "Â÷°¡ ¸ØÃè½À´Ï´Ù." << endl;
		return;
	}
	curSpeed -= BRK_STEP;
	cout << "³¢ÀÍ~" << endl;
}