#include "Default.h"

//1. Ŭ���� ���� ���̵�, ��, �̸�
//2. �����ڷ� ���¸����
//3. �Ա� �޼���
//4. ��� �޼���
//5. ID�������� �޼���
//6. ���� ��� �޼���

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
//		cout << "���� ���̵�: " << id << endl;
//		cout << "�̸�: " << name << endl;
//		cout << "�ܾ�: " << money << endl;
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
//	cout << "id �Է�: " << endl;
//	cin >> id;
//	cout << "�̸� �Է�: " << endl;
//	cin >> name;
//	cout << "���� �ݾ�: " << endl;
//	cin >> money;
//	arr[accNum++] = new Account(id, money, name);
//}
//
//void DepositMoney()
//{
//	int id, money;
//	cout << "id �Է�: " << endl;
//	cin >> id;
//	cout << "�Ա� �ݾ�: " << endl;
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
//	cout << "id �Է�: " << endl;
//	cin >> id;
//	cout << "��� �ݾ�: " << endl;
//	cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (id == arr[i]->GetId())
//		{
//			if (arr[i]->WithdrawalMoney(money) == 0)
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
//
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
//	cout << "�޴� ���� :" << endl;
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
