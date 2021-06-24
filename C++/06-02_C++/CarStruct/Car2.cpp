#include "Car2.h"
#include <iostream>
#include<cstring>

using namespace std;

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
		fuleGauge -= CAR_CONST::FUEL_STEP;

	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
	cout << "�ο�~" << endl;
}
void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		cout << "���� ������ϴ�." << endl;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
	cout << "����~" << endl;
}