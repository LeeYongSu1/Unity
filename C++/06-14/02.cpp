#include "Default.h"

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(char * name, int age) : age(age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void ShowMyFriendInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo()
	{
		delete[] name;
	}
};

class MyFriendEdtailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendEdtailInfo(char * addr, char * phone, char * name, int age) : MyFriendInfo(name, age)
	{
		this->addr = new char[strlen(addr) + 1];
		strcpy_s(this->addr, strlen(addr) + 1, addr);
		this->phone = new char[strlen(phone) + 1];
		strcpy_s(this->phone, strlen(phone) + 1, phone);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
	~MyFriendEdtailInfo()
	{
		delete[] addr;
		delete[] phone;
	}
};

int main2(void)
{
	char name[20] = { "lee" };
	char addr[10] = { "asdfasd" };
	char phone[10] = { "123123" };
	int age = 30;
	MyFriendEdtailInfo * info = new MyFriendEdtailInfo(addr, phone, name, age);
	info->ShowMyFriendDetailInfo();

	return 0;
}