#pragma once
using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}
struct Car
{
	char gamerID[CAR_CONST::ID_LEN];
	int fuleGauge;
	int curSpeed;

	void ShowCarState();
	void Accel();
	void Break();

};