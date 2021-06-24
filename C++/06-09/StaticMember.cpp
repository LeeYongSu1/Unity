#include "Default.h"

class SoSimple
{
private:
	static int simObjCnt;
	int num;
public:
	SoSimple(int num)
	{
		simObjCnt++;
		this->num = num;
		cout << simObjCnt << "¹øÂ° SoSimple°´Ã¼" << endl;
		cout << this->num << endl;
	}
};
int SoSimple::simObjCnt = 0;

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "¹øÂ° SoComplex °´Ã¼" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "¹øÂ° SoComplex°´Ã¼" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main4(void)
{
	SoSimple sim1(10);
	SoSimple sim2(20);

	SoComplex cmx1;
	SoComplex cmx2 = cmx1;
	SoComplex();

	return 0;
}