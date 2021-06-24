#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
		: age(myage)
	{
		
		name = new char[strlen(myname) + 1];
		strcpy_s(name, strlen(myname) + 1, myname);
		
	}

	void ShowPersoinInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}

	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main8(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);
	man1.ShowPersoinInfo();
	man2.ShowPersoinInfo();
	return 0;
}