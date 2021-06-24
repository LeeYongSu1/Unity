#include <iostream>
#include<cstring>
#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

using namespace std;
struct Car
{
	char gamerID[ID_LEN];
	int fuleGauge;
	int curSpeed;

	void ShowCarState();
	void Accel();
	void Break();
	
};



int main()
{
	Car run99 = { "run99",100,0 };
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.Break();
	run99.ShowCarState();

	return 0;
}
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
void Car:: Break()
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