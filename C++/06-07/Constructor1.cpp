#include <iostream>

using namespace std;
class SimpleClass
{
	int num1;
	int num2;
public:
	SimpleClass()//매개변수가 없는 생성자  void
	{
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n)
	{
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n1, int n2)
	{
		num1 = n1;
		num2 = n2;
	}
	void ShowData()const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main2()
{
	SimpleClass sc;
	SimpleClass* ptr0 = new SimpleClass;
	ptr0->ShowData();

	delete ptr0;
	return 0;
}