#include "Default.h"

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout << "create obj: " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};

int main(void)
{
	Temporary(100);//임시 객체를 생성하는 방법
	cout << "************after make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	cout << "************after make!" << endl << endl;

	const Temporary& ref = Temporary(300);
	cout << "************after make!" << endl << endl;
	return 0;
}