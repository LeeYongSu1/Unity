#pragma once

using namespace std;
struct Car
{
	enum {
		ID_LEN =20,
		MAX_SPD =200,
		FUEL_STEP= 2,
		ACC_STEP =10,
		BRK_STEP =10,
	};
	char gamerID[ID_LEN];
	int fuleGauge;
	int curSpeed;

	void ShowCarState();
	void Accel();
	void Break();

};




