//#include "Default.h"
//
//class Person
//{
//	char* name;
//	int age;
//public:
//	Person(const char* myname, int myage) : age(myage)
//	{
//		int len = strlen(myname) + 1;
//		name = new char[len];
//		strcpy_s(name, strlen(myname) + 1, myname);
//	}
//	Person(const Person& copy) : age(copy.age)
//	{
//		name = new char[strlen(copy.name) + 1];
//		strcpy_s(name, strlen(copy.name) + 1, copy.name);
//	}
//	Person& operator = (const Person& ref)//�̴ϼ� ������ ����� �ȵ�- �����ڰ� �ƴ϶� �Լ��̱⶧����
//	{
//		delete[]name;
//		//���� ������ �����ε������� ���ڿ��� �����ϰ� �����Ѵ�.
//		int len = strlen(ref.name) + 1;
//		name = new char[len];
//		strcpy_s(name, len, ref.name);
//		age = ref.age;
//
//		return *this;
//	}
//	void ShowPersonInfo()const
//	{
//		cout << "�̸�: " << name << endl;
//		cout << "����: " << age << endl;
//	}
//	~Person()
//	{
//		delete[]name;
//		cout << "called destructor!" << endl;
//	}
//};
//
//int main(void)
//{
//	Person man1("Lee", 29);
//	Person man2("Kim", 30);
//	man2 = man1;
//	Person man3("Park", 40);
//	Person man4 = man3;
//	man1.ShowPersonInfo();
//	man2.ShowPersonInfo();
//	man4.ShowPersonInfo();
//	return 0;
//}