#include "Default.h"

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2)
	{

	}
	SoSimple(SoSimple& copy)
		:num1(copy.num1), num2(copy.num2)
	{
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}
	void ShowSimpleDate()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main11(void)
{
	SoSimple sim1(15, 40);
	cout << "���� �� �ʱ�ȭ ����" << endl;
	SoSimple sim2 = sim1;
	cout << "���� �� �ʱ�ȭ ����" << endl;
	sim2.ShowSimpleDate();
	
	return 0;
}