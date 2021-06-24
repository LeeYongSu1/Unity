#include <iostream>

using namespace std;
class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage) :age(myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name,len, myname);
	}
	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	void SetPersonInfo(char* myname, int myage)
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

int main3(void)
{
	//Person parr[3];	//객체 배열 선언
	Person* parr[3];	//객체 포인터 배열
	char namestr[100];
	//char* strptr;
	int age;
	//int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;

		/*len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy_s(strptr, strlen(namestr)+1, namestr);
		parr[i].SetPersonInfo(strptr, age);*/
		parr[i] = new Person(namestr, age);
		parr[i]->ShowPersonInfo();
	}

	for (int i = 0; i < 3; i++)
	{
		delete parr[i];
	}
	return 0;
}