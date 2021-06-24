#include "Default.h"

class SoBase
{
private:
	int baseNum;
public:
	SoBase(int n) :baseNum(n)
	{
		cout << "SoBase()" <<baseNum<< endl;
		
	}
	~SoBase()
	{
		cout << "!SoBase()" << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	
	SoDerived(int n) : SoBase(n), derivNum(n)
	{
		cout << "SoDerivec(int n1, int n2)" << endl;
	}
	~SoDerived()
	{
		cout << "!SoDerived() : " << derivNum << endl;
	}
	
};

int main13(void)
{
	SoDerived drv1(15);
	SoDerived drv2(27);

	return 0;
}