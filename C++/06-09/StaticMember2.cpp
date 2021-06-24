#include "Default.h"

class SoSimple
{
public:
	static int simobjCnt;
public:
	SoSimple()
	{
		simobjCnt++;
	}
};
int SoSimple::simobjCnt = 0;

int main5(void)
{
	cout << SoSimple::simobjCnt << "¹øÂ° SoSimple °´Ã¼" << endl;
	SoSimple sim1;
	SoSimple sim2;
	cout << SoSimple::simobjCnt << "¹øÂ° SoSimple°´Ã¼" << endl;
	cout << sim1.simobjCnt << "¹øÂ° SoSimple °´Ã¼" << endl;
	cout << sim2.simobjCnt << "¹øÂ° SoSimple °´Ã¼" << endl;

	return 0;
}