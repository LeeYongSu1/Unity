#include "Default.h"

//1. 클래스 생성 아이디, 돈, 이름
//2. 생성자로 계좌만들기
//3. 입금 메서드
//4. 출금 메서드
//5. ID가져오는 메서드
//6. 정보 출력 메서드

//class Account
//{
//private:
//	int id;
//	int money;
//	char* name;
//public:
//	Account(const int id, int money, const char* name) :
//		id(id), money(money)
//	{
//		this->name = new char[strlen(name) + 1];
//		strcpy_s(this->name, strlen(name) + 1, name);
//	}
//	int GetId() const
//	{
//		return id;
//	}
//	void DepositMoney(int money)
//	{
//		this->money += money;
//	}
//	int WithdrawalMoney(int money)
//	{
//		this->money -= money;
//		return this->money;
//	}
//	void ShowAccountInfo() const
//	{
//		cout << "계좌 아이디: " << id << endl;
//		cout << "이름: " << name << endl;
//		cout << "잔액: " << money << endl;
//	}
//	~Account()
//	{
//		delete[]name;
//	}
//};
//Account* arr[100];
//int accNum = 0;
//
//
//void MakeAccount()
//{
//	int id;
//	int money;
//	char name[30];
//
//	cout << "id 입력: " << endl;
//	cin >> id;
//	cout << "이름 입력: " << endl;
//	cin >> name;
//	cout << "개설 금액: " << endl;
//	cin >> money;
//	arr[accNum++] = new Account(id, money, name);
//}
//
//void DepositMoney()
//{
//	int id, money;
//	cout << "id 입력: " << endl;
//	cin >> id;
//	cout << "입금 금액: " << endl;
//	cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (id == arr[i]->GetId())
//		{
//			arr[i]->DepositMoney(money);
//		}
//	}
//}
//
//void WithdrawalMoney()
//{
//	int id, money;
//	cout << "id 입력: " << endl;
//	cin >> id;
//	cout << "출금 금액: " << endl;
//	cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (id == arr[i]->GetId())
//		{
//			if (arr[i]->WithdrawalMoney(money) == 0)
//			{
//				cout << "잔액부족" << endl << endl;
//				return;
//			}
//
//
//			cout << "출금완료" << endl << endl;
//			return;
//		}
//	}
//}
//
//void ShowMenu()
//{
//	cout << "1. 계좌 개설" << endl;
//	cout << "2. 입금" << endl;
//	cout << "3. 출금" << endl;
//	cout << "4. 계좌 정보" << endl;
//	cout << "5. 나가기" << endl;
//}
//void ShowAllinfo()
//{
//	for (int i = 0; i < accNum; i++)
//	{
//		arr[i]->ShowAccountInfo();
//	}
//}
//
//void ChoiceMenu()
//{
//	int choice;
//	int end;
//	cout << "메뉴 선택 :" << endl;
//	cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			MakeAccount();
//			break;
//		case 2:
//			DepositMoney();
//			break;
//		case 3:
//			WithdrawalMoney();
//			break;
//		case 4:
//			ShowAllinfo();
//		case 5:
//			return;
//		default:
//			break;
//		}
//		
//	
//}
//
//
//int main(void)
//{
//	while (true)
//	{
//		ShowMenu();
//		ChoiceMenu();
//		
//	}
//	
//	return 0;
//}
