#include "Default.h"

class CountryArea
{
public:
	const static int RUSSIA = 1707540;
	const static int CANADA = 998467;
	const static int CHINA = 957290;
	const static int SOUTH_KIREA = 9922;
};
class SoSimple
{
private:
	int num1;
	mutable int num2;
public:
	SoSimple(int n1, int n2) :num1(n1),num2(n2){}

	void CopyToNum2()const
	{
		num2 = num1;
	}
	void ShowSimpleData() const
	{
		cout << num1 << ", " << num2 << endl;
	}
};

int main6(void)
{
	cout << "러시아 면적: " << CountryArea::RUSSIA << "km" << endl;
	cout << "캐나다 면적: " << CountryArea::CANADA << "km" << endl;
	cout << "중국 면적: " << CountryArea::CANADA << "km" << endl;
	cout << "한국 면적: " << CountryArea::SOUTH_KIREA << "km" << endl;

	return 0;
}