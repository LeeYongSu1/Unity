#include "Default.h"
#include "Bankin_Account.h"

Account::Account(int ID, int money, const char* name)
	: accID(ID), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy_s(cusName, strlen(name) + 1, name);
}

Account::Account(const Account& ref)
	: accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy_s(cusName, strlen(ref.cusName) + 1, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "????ID: " << accID << endl;
	cout << "??  ??: " << cusName << endl;
	cout << "??  ??: " << balance << endl;
}

Account::~Account()
{
	delete[]cusName;
}