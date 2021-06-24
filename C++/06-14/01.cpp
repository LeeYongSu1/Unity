#include "Default.h"

class Car
{
private:
	int gasloineGauge;
public:
	Car() : gasloineGauge(100)
	{
		
	}
	Car(int n1) : gasloineGauge(n1)
	{

	}
	int GetGasGauge()
	{
		return gasloineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar() : electricGauge(100)
	{

	}
	HybridCar(int n1, int  n2) : Car(n1), electricGauge(n2)
	{

	}
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar() : waterGauge(100)
	{

	}
	HybridWaterCar(int n1, int n2, int n3) : HybridCar(n1, n2), waterGauge(n3)
	{

	}
	void ShowCurrentGauge()
	{
		cout << " :" << GetGasGauge() << endl;
		cout << " :" << GetElecGauge() << endl;
		cout << " :" << waterGauge << endl;
	}
};

int main1(void)
{
	HybridWaterCar* buwcar = new HybridWaterCar(20, 30, 40);
	buwcar->ShowCurrentGauge();
	delete buwcar;

	return 0;
}