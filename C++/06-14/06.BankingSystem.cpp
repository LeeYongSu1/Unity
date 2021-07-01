///*
// * Banking System Ver 0.2
// * �ۼ���: ������
// * ��  ��: Account Ŭ���� ����, ��ü ������ �迭 ����
// */
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int NAME_LEN = 20;
//enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//
//class Account
//{
//private:
//	int accID;      // ���¹�ȣ
//	int balance;    // ��    ��
//	char* cusName;   // �����̸�
//
//public:
//	Account(int ID, int money, const char* name)
//		: accID(ID), balance(money)
//	{
//		cusName = new char[strlen(name) + 1];
//		strcpy_s(cusName, strlen(name) + 1, name);
//	}
//
//	int GetAccID() { return accID; }
//
//	void Deposit(int money)
//	{
//		balance += money;
//	}
//
//	int Withdraw(int money)    // ��ݾ� ��ȯ, ���� �� 0
//	{
//		if (balance < money)
//			return 0;
//
//		balance -= money;
//		return money;
//	}
//
//	void ShowAccInfo()
//	{
//		cout << "����ID: " << accID << endl;
//		cout << "��  ��: " << cusName << endl;
//		cout << "��  ��: " << balance << endl;
//	}
//
//	~Account()
//	{
//		delete[]cusName;
//	}
//};
//
//class AccountHandler
//{
//private:
//	Account* accArr[100];   // Account ������ ���� �迭
//	int accNum;        // ����� Account ��
//public:
//	AccountHandler();
//	void ShowMenu(void);       // �޴����
//	void MakeAccount(void);    // ���°����� ���� �Լ�
//	void DepositMoney(void);       // ��    ��
//	void WithdrawMoney(void);      // ��    ��
//	void ShowAllAccInfo(void);     // �ܾ���ȸ
//	~AccountHandler();
//};
//AccountHandler::AccountHandler() :accNum(0)
//{}
//void AccountHandler::ShowMenu(void)
//{
//	cout << "-----Menu------" << endl;
//	cout << "1. ���°���" << endl;
//	cout << "2. ��    ��" << endl;
//	cout << "3. ��    ��" << endl;
//	cout << "4. �������� ��ü ���" << endl;
//	cout << "5. ���α׷� ����" << endl;
//}
//void AccountHandler::MakeAccount(void)
//{
//	int id;
//	char name[NAME_LEN];
//	int balance;
//
//	cout << "[���°���]" << endl;
//	cout << "����ID: ";	cin >> id;
//	cout << "��  ��: ";	cin >> name;
//	cout << "�Աݾ�: ";	cin >> balance;
//	cout << endl;
//
//	accArr[accNum++] = new Account(id, balance, name);
//}
//void AccountHandler::DepositMoney(void)
//{
//	int money;
//	int id;
//	cout << "[��    ��]" << endl;
//	cout << "����ID: ";	cin >> id;
//	cout << "�Աݾ�: ";	cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetAccID() == id)
//		{
//			accArr[i]->Deposit(money);
//			cout << "�ԱݿϷ�" << endl << endl;
//			return;
//		}
//	}
//	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
//}
//void AccountHandler::WithdrawMoney(void)
//{
//	int money;
//	int id;
//	cout << "[��    ��]" << endl;
//	cout << "����ID: ";	cin >> id;
//	cout << "��ݾ�: ";	cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetAccID() == id)
//		{
//			if (accArr[i]->Withdraw(money) == 0)
//			{
//				cout << "�ܾ׺���" << endl << endl;
//				return;
//			}
//
//			cout << "��ݿϷ�" << endl << endl;
//			return;
//		}
//	}
//	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
//}
//void AccountHandler::ShowAllAccInfo(void)
//{
//	for (int i = 0; i < accNum; i++)
//	{
//		accArr[i]->ShowAccInfo();
//		cout << endl;
//	}
//}
//AccountHandler::~AccountHandler() 
//{
//	for (int i = 0; i < accNum; i++)
//	{
//		delete accArr[i];
//	}
//}
//int main8(void)
//{
//	int choice;
//	AccountHandler handler;
//	while (1)
//	{
//		handler.ShowMenu();
//		cout << "����: ";
//		cin >> choice;
//		cout << endl;
//
//		switch (choice)
//		{
//		case MAKE:
//			handler.MakeAccount();
//			break;
//		case DEPOSIT:
//			handler.DepositMoney();
//			break;
//		case WITHDRAW:
//			handler.WithdrawMoney();
//			break;
//		case INQUIRE:
//			handler.ShowAllAccInfo();
//			break;
//		case EXIT:
//			return 0;
//		default:
//			cout << "Illegal selection.." << endl;
//		}
//	}
//	return 0;
//}