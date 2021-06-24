//#include "Default.h"
//#include "TestHeader.h"
//enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//class Account
//{
//private:
//	int id;
//	int money;
//	char* name;
//public:
//	Account(const int id, int money, const char* name) :id(id), money(money)
//	{
//		this->name = new char[strlen(name) + 1];
//		strcpy_s(this->name, strlen(name) + 1, name);
//	}
//	Account(Account& copy) :id(copy.id), money(copy.money)
//	{
//		this->name = new char[strlen(copy.name) + 1];
//		strcpy_s(name, strlen(copy.name) + 1, copy.name);
//	}
//	void DepositMoney(int money)
//	{
//		this->money += money;
//	}
//	int withdrawalMoney(int money)
//	{
//		if (this->money < money)
//			return 0;
//
//		this->money -= money;
//		return money;
//	}
//	int GetId() const
//	{
//		return id;
//	}
//
//	void ShowAllInfo() const
//	{
//		cout << "ID : " << id << endl;
//		cout << "name: " << name << endl;
//		cout << "money: " << money << endl;
//	}
//	~Account()
//	{
//		delete[] name;
//	}
//};
//
//Account* arr[100];
//int arrNum = 0;
//
//void MakeAccount()
//{
//	int id, money;
//	char name[30];
//
//	cout << "���� ID�Է�: "; cin >> id; cout << endl;
//	cout << "���� �̸� �Է�: "; cin >> name; cout << endl;
//	cout << "������ �ݾ�: "; cin >> money; cout << endl;
//
//	arr[arrNum++] = new Account(id, money, name);
//}
//
//void DepositMoney()
//{
//	int id;
//	int money;
//
//	cout << "���� ���̵� �Է�: "; cin >> id; cout << endl;
//	cout << "�Ա��Ͻ� �ݾ� : "; cin >> money; cout << endl;
//
//	for (int i = 0; i < arrNum; i++)
//	{
//		if (id == arr[i]->GetId())
//		{
//			arr[i]->DepositMoney(money);
//		}
//	}
//	cout << money << " �� �Ա� �Ϸ�" << endl;
//}
//
//void WithdrawalMoney()
//{
//	int id, money;
//	cout << "id �Է�: "; cin >> id; cout << endl;
//	cout << "��� �ݾ�: "; cin >> money; cout << endl;
//	
//
//	for (int i = 0; i < arrNum; i++)
//	{
//		if (id == arr[i]->GetId())
//		{
//			if (arr[i]->withdrawalMoney(money) == 0)
//			{
//				cout << "�ܾ׺���" << endl << endl;
//				return;
//			}
//
//
//			cout << "��ݿϷ�" << endl << endl;
//			return;
//		}
//	}
//}
//void ShowMenu()
//{
//	cout << "1. ���� ����" << endl;
//	cout << "2. �Ա�" << endl;
//	cout << "3. ���" << endl;
//	cout << "4. ���� ����" << endl;
//	cout << "5. ������" << endl;
//}
//void ShowAllinfo()
//{
//	for (int i = 0; i < arrNum; i++)
//	{
//		arr[i]->ShowAllInfo();
//	}
//}
//
//int main2(void)
//{
//	int choice;
//
//	while (true)
//	{
//		ShowMenu();
//		cout << "����: ";
//		cin >> choice;
//		cout << endl;
//
//		switch (choice)
//		{
//			case MAKE:
//				MakeAccount();
//				break;
//			case DEPOSIT:
//				DepositMoney();
//				break;
//			case WITHDRAW:
//				WithdrawalMoney();
//				break;
//			case INQUIRE:
//				ShowAllinfo();
//				break;
//			case EXIT:
//				return 0;
//			default:
//				break;
//		}
//	}
// for (int i = 0; i < arrNum; i++)
//		delete arr[i];
//	return 0;
//}