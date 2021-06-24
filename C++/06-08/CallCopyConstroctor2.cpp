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
	cout << "주소2" << &ob << endl;
	return ob;
}

int main22(void)
{
	SoSimple obj(7);
	cout << "주소1" << &obj << endl;
	cout << "함수호출 전:" << endl;
	SimpleFuncObj(obj);
	cout << "함수 호출 후:" << endl;

	return 0;
}