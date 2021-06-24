#include "Default.h"

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{}
	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() {
		cout << "num: " << num << endl;
	}
};

SoSimple& SimpleFuncObj(SoSimple &ob)
{
	cout << "return ����" << endl;
	cout << "�ּ�" << &ob << endl;
	return ob;
}

int main66(void)
{
	SoSimple obj(7);
	cout << "obj�ּ�:" << &obj << endl;
	SimpleFuncObj(obj).AddNum(30).ShowData();
	cout << "obj�ּ�2:" << &obj << endl;
	obj.ShowData();
	
	return 0;
}