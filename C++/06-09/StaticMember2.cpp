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
	cout << SoSimple::simobjCnt << "��° SoSimple ��ü" << endl;
	SoSimple sim1;
	SoSimple sim2;
	cout << SoSimple::simobjCnt << "��° SoSimple��ü" << endl;
	cout << sim1.simobjCnt << "��° SoSimple ��ü" << endl;
	cout << sim2.simobjCnt << "��° SoSimple ��ü" << endl;

	return 0;
}