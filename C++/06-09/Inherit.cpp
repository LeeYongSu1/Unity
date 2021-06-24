#include "Default.h"

class Person
{
private:
	int age;
	char* name;
public:
	Person(int myage, const char* myname) : age(myage)
	{
		cout << "부모 생성자" << endl;
		name = new char[strlen(myname) + 1];
		strcpy_s(name, strlen(myname) + 1, myname);
	}
	Person(const Person& copy) :age(copy.age)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy_s(name, strlen(copy.name) + 1, copy.name);
	}
	void WhatYourName()const
	{
		cout << "My name is" << name << endl;
	}
	void HowOldAreYou()const
	{
		cout << "I'm" << age << " years old" << endl;
	}
	~Person()
	{
		delete[]name;
	}
};

class UnivStudent : public Person
{
private:
	char* major;
public:
	UnivStudent(const char* myname, int myage, const char* mymajor) :Person(myage, myname)
	{
		cout << "자식 생성자" << endl;
		major = new char[strlen(mymajor) + 1];
		strcpy_s(major, strlen(mymajor) + 1, mymajor);
		//자식 클래스의 생성자는 부모클래스의 생성자를 먼저 호출해서 초기화할 의무를 가진다.
	}
	/*UnivStudent(const UnivStudent &copy)
	{
		major = new char[strlen(copy.major) + 1];
		strcpy_s(major, strlen(copy.major) + 1, copy.major);
	}*/
	void WhoAreYou()const
	{
		WhatYourName();
		HowOldAreYou();
		cout << "My major is" << major << endl << endl;
	}
};

int main11(void)
{
	UnivStudent ustd1("Lee", 22, "computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("yoon", 21, "Electronic");
	ustd2.WhoAreYou();
	return 0;
}