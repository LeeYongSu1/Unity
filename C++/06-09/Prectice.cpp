#include "Default.h"

class Car	//�⺻ ���� �ڵ���
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

class HybridCar : public Car	//���̺긮�� �ڵ���
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

class HybridWaterCar : public HybridCar	  //���̺긮�� ����ī
{
private:
	int waterGauge;
public:
	HybridWaterCar(int water, int elec, int gas) :waterGauge(water),HybridCar(elec, gas)
	{
		
	}
	void ShowCurrentGauge()
	{
		cout << "���ָ� ��: " << GetGasGauge() << endl;
		cout << "���� ���� ��: " << GetElecGauge() << endl;
		cout << "���� ���� ��: " << waterGauge << endl;
	}
};

int main(void)
{
	HybridWaterCar wcar(100, 100, 100);
	wcar.ShowCurrentGauge();

	return 0;
}