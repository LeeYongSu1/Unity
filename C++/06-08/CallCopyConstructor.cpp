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
	cout << "return 捞傈" << endl;
	cout << "林家" << &ob << endl;
	return ob;
}

int main66(void)
{
	SoSimple obj(7);
	cout << "obj林家:" << &obj << endl;
	SimpleFuncObj(obj).AddNum(30).ShowData();
	cout << "obj林家2:" << &obj << endl;
	obj.ShowData();
	
	return 0;
}