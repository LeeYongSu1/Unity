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
//	Person& operator = (const Person& ref)//이니셜 라이즈 멤버가 안됨- 생성자가 아니라 함수이기때문에
//	{
//		delete[]name;
//		//대입 연산자 오버로딩에서는 문자열을 삭제하고 시작한다.
//		int len = strlen(ref.name) + 1;
//		name = new char[len];
//		strcpy_s(name, len, ref.name);
//		age = ref.age;
//
//		return *this;
//	}
//	void ShowPersonInfo()const
//	{
//		cout << "이름: " << name << endl;
//		cout << "나이: " << age << endl;
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