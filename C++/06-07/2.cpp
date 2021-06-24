#include <iostream>

using namespace std;
class SoSimple
{
private:
	int num;
public:
	SoSimple(){}
	SoSimple(int n) :num(n){}

	void ShowResult()
	{
		cout << num << endl;
	}
};

int main6(void)
{
	SoSimple simObj1(2);
	simObj1.ShowResult();
	SoSimple* simPtr = new SoSimple(5);
	simPtr->ShowResult();
	SoSimple simObj2;
	SoSimple* simObj3 = new SoSimple;
	simObj3->ShowResult();

	delete simPtr;
	delete simObj3;

	return 0;
}