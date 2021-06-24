#include "Default.h"

namespace Parse {
	enum POS {
		CLERK,
		SENIOR,
		ASSIST,
		MANAGER
	};
	void ShowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "대리" << endl;
			break;
		case ASSIST:
			cout << "과장" << endl;
			break;
		case MANAGER:
			cout << "부장" << endl;
			break;
		default:
			break;
		}
	}
}
class NameCard
{

private:
	char* name;
	char* cp_name;
	char* phone;
	int pos;
public:
	NameCard(const char* _name, const char* _cp_name, const char* _phone, int _pos) :pos(_pos)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
		cp_name = new char[strlen(_cp_name) + 1];
		strcpy_s(cp_name, strlen(_cp_name) + 1, _cp_name);
		phone = new char[strlen(_phone) + 1];
		strcpy_s(phone, strlen(_phone) + 1, _phone);

	}
	NameCard(const NameCard& copy) :pos(copy.pos)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy_s(name, strlen(copy.name) + 1, copy.name);
		cp_name = new char[strlen(copy.cp_name) + 1];
		strcpy_s(cp_name, strlen(copy.cp_name) + 1, copy.cp_name);
		phone = new char[strlen(copy.phone) + 1];
		strcpy_s(phone, strlen(copy.phone) + 1, copy.phone);
	}

	void ShowInfo() const
	{
		cout << "이름 :" << name << endl;
		cout << "회사 :" << cp_name << endl;
		cout << "번호 :" << phone << endl;
		cout << "직급 :"; Parse::ShowPositionInfo(pos);
		cout << endl;
	}
	~NameCard()
	{
		delete[]name;
		delete[]cp_name;
		delete[]phone;
	}
};




int main12(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", Parse::CLERK);
	NameCard manClekr2 = manClerk;
	NameCard manSENIOR("Hong", "OrangEng", "010-3333-4444", Parse::SENIOR);
	NameCard manAssist("Kim", "SoGood", "010-5555-6666", Parse::ASSIST);
	manClerk.ShowInfo();
	manClekr2.ShowInfo();
	manSENIOR.ShowInfo();
	manAssist.ShowInfo();
	return 0;
}