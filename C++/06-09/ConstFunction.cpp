#include "Default.h"

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n ): num(n)
	{}
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const
	{
		cout << "num: " << num << endl;
	}
	void SimpleFunc()
	{
		cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc()const
	{
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple& obj)
{
	obj.SimpleFunc();
}

int main1(void)
{
	SoSimple obj1(2);
	const SoSimple obj2(7);
	obj1.SimpleFunc();
	obj2.SimpleFunc();
	YourFunc(obj1);
	YourFunc(obj2);
	

	return 0;
}