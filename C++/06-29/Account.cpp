#include "Account.h"
#include "Default.h"

Account::Account(int accId, int balance, const char* cusName) : accId(accId), balance(balance)
{
	this->cusName = new char[strlen(cusName) + 1];
	strcpy_s(this->cusName, strlen(cusName) + 1, cusName);
}

Account::Account(const Account& copy): accId(copy.accId), balance(copy.balance)
{
	this->cusName = new char[strlen(copy.cusName) + 1];
	strcpy_s(this->cusName, strlen(copy.cusName) + 1, copy.cusName);
}

void Account::ShowAllAccInfo() const
{
	cout << "°èÁÂ Id: " << this->accId << endl;
	cout << "ÀÌ¸§: " << this->cusName << endl;
	cout << "ÀÜ¾×: " << this->balance << endl;
}

void Account::DepositMoney(int money)
{
	balance += money;
}

int Account::WithdrawMoney(int money)
{
	if (balance < money)
		return 0;
	balance -= money;
	return balance;
}

int Account::GetId()const
{
	return accId;
}

Account::~Account() { delete[]cusName; }