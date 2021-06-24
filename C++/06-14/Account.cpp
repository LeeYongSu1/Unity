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
//	int Account::Withdraw(int money)    // 출금액 반환, 부족 시 0
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
//		cout << "계좌ID: " << accID << endl;
//		cout << "이  름: " << cusName << endl;
//		cout << "잔  액: " << balance << endl;
//	}
//
//	Account::~Account()
//	{
//		delete[]cusName;
//	}
