#include "Default.h"

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n):num(n)
	{}
	SoSimple(const SoSimple& copy) :num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}
	void ShowData()
	{
		cout << "num:" << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	ob.ShowData();
	cout << "�ּ�2" << &ob << endl;
	return ob;
}

int main22(void)
{
	SoSimple obj(7);
	cout << "�ּ�1" << &obj << endl;
	cout << "�Լ�ȣ�� ��:" << endl;
	SimpleFuncObj(obj);
	cout << "�Լ� ȣ�� ��:" << endl;

	return 0;
}