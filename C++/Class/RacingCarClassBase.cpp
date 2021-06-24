#include <iostream>
#include<cstring>


using namespace std;
namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD  = 200,
		FUEL_STEP  =2,
		ACC_STEP =10,
		BRK_STEP =10
	};


	Class Car
	{
		private::
			char gamerID[CAR_CONST::ID_LEN];
			int fuleGauge;
			int curSpeed;
		public::
			void InitMembers(char* ID, int fuel);
			void ShowCarState();
			void Accel();
			void Break();

	};
}

void Car::InitMembers(const char* ID, int fuel)
{
	strcpy_s(gamerID, sizeof(gamerID), ID);
	fuleGauge = fuel;
	curSpeed = 0;
}

void Car:: ShowCarState()
{
	cout << "¼ÒÀ¯ÀÚ ID: " << car.gamerID << endl;
	cout << "¿¬·á·®: " << car.fuleGauge << endl;
	cout << "ÇöÀç¼Óµµ: " << car.curSpeed << endl;
}

void Car:: Accel()
{
	if (car.fuleGauge <= 0)
	{
		return;
	}
	
	else
		car.fuleGauge -= FUEL_STEP;

	if (car.curSpeed + ACC_STEP >= MAX_SPD)
	{
		car.curSpeed = MAX_SPD;
		return;
	}
	car.curSpeed += ACC_STEP;
	cout << "ºÎ¿õ~" << endl;
}

void Car::Break()
{
	if (car.curSpeed < BRK_STEP)
	{
		car.curSpeed = 0;
		cout << "Â÷°¡ ¸ØÃè½À´Ï´Ù." << endl;
		return;
	}
	car.curSpeed -= BRK_STEP;
	cout << "³¢ÀÍ~" << endl;
}

int main()
{
	Car run99 = { "run99",100,0 };
	Accel(run99);
	Accel(run99);
	Accel(run99);
	Accel(run99);
	ShowCarState(run99);
	Break(run99);
	ShowCarState(run99);
	Break(run99);
	Break(run99);
	Break(run99);
	Break(run99);
	Break(run99);
	return 0;
}