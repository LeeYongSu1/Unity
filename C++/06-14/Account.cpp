//#include "Account.h"
//
//	Account::Account(int ID, int money, const char* name)
//		: accID(ID), balance(money)
//	{
//		cusName = new char[strlen(name) + 1];
//		strcpy_s(cusName, strlen(name) + 1, name);
//	}
//
//	int Account::GetAccID() { return accID; }
//
//	void Account::Deposit(int money)
//	{
//		balance += money;
//	}
//
//	int Account::Withdraw(int money)    // ��ݾ� ��ȯ, ���� �� 0
//	{
//		if (balance < money)
//			return 0;
//
//		balance -= money;
//		return money;
//	}
//
//	void Account::ShowAccInfo()
//	{
//		cout << "����ID: " << accID << endl;
//		cout << "��  ��: " << cusName << endl;
//		cout << "��  ��: " << balance << endl;
//	}
//
//	Account::~Account()
//	{
//		delete[]cusName;
//	}
