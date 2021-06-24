#include "Car.h"
#include "Default.h"

void Car::ShowCarState()
{
	cout << "������ ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuleGauge << endl;
	cout << "����ӵ�: " << curSpeed << endl;
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
	cout << "�ο�~" << endl;
}
void Car::Break()
{
	if (curSpeed < BRK_STEP)
	{
		curSpeed = 0;
		cout << "���� ������ϴ�." << endl;
		return;
	}
	curSpeed -= BRK_STEP;
	cout << "����~" << endl;
}