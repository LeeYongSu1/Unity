//#include <iostream>
//#include<cstring>
//#define ID_LEN 20
//#define MAX_SPD 200
//#define FUEL_STEP 2
//#define ACC_STEP 10
//#define BRK_STEP 10
//
//using namespace std;
//struct Car
//{
//	char gamerID[ID_LEN];
//	int fuleGauge;
//	int curSpeed;
//};
//
//void ShowCarState(const Car& car)
//{
//	cout << "������ ID: " << car.gamerID << endl;
//	cout << "���ᷮ: " << car.fuleGauge << endl;
//	cout << "����ӵ�: " << car.curSpeed << endl;
//}
//
//void Accel(Car& car)
//{
//	if (car.fuleGauge <= 0)
//	{
//		return;
//	}
//	
//	else
//		car.fuleGauge -= FUEL_STEP;
//
//	if (car.curSpeed + ACC_STEP >= MAX_SPD)
//	{
//		car.curSpeed = MAX_SPD;
//		return;
//	}
//	car.curSpeed += ACC_STEP;
//	cout << "�ο�~" << endl;
//}
//
//void Break(Car& car)
//{
//	if (car.curSpeed < BRK_STEP)
//	{
//		car.curSpeed = 0;
//		cout << "���� ������ϴ�." << endl;
//		return;
//	}
//	car.curSpeed -= BRK_STEP;
//	cout << "����~" << endl;
//}
//
//int main()
//{
//	Car run99 = { "run99",100,0 };
//	Accel(run99);
//	Accel(run99);
//	Accel(run99);
//	Accel(run99);
//	ShowCarState(run99);
//	Break(run99);
//	ShowCarState(run99);
//	Break(run99);
//	Break(run99);
//	Break(run99);
//	Break(run99);
//	Break(run99);
//	return 0;
//}