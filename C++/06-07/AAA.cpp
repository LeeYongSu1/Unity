#include <iostream>

using namespace std;

class AAA
{
public:
	AAA()
	{
		cout << "empty object" << endl;
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB {
private:
	AAA &ref; //참조자도 선언과 동시에 초기화가 되어야 오류가 나지 않는다.
	const int &num;
public:
	BBB(AAA &r, const int &n)
		:ref(r), num(n)
	{}
	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num" << num << endl;
	}
};

int main3(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();

	return 0;
}