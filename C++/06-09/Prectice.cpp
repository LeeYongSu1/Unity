#include "Default.h"

class Car	//기본 연료 자동차
{
private:
	int gasolineGauge;
public:
	Car(int gas) :gasolineGauge(gas)
	{
		
	}
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car	//하이브리드 자동차
{
private:
	int electricGauge;
public:
	HybridCar(int elec, int gas):Car(gas), electricGauge(elec)
	{
		
	}
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar	  //하이브리드 워터카
{
private:
	int waterGauge;
public:
	HybridWaterCar(int water, int elec, int gas) :waterGauge(water),HybridCar(elec, gas)
	{
		
	}
	void ShowCurrentGauge()
	{
		cout << "가솔린 양: " << GetGasGauge() << endl;
		cout << "남은 전기 양: " << GetElecGauge() << endl;
		cout << "남은 물의 양: " << waterGauge << endl;
	}
};

int main(void)
{
	HybridWaterCar wcar(100, 100, 100);
	wcar.ShowCurrentGauge();

	return 0;
}