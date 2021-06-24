#pragma once
#include "Default.h"

void MakeAccount();
void DepositMoney();
void WithdrawalMoney();
void WithdrawalMoney();
void ShowMenu();
void ShowAllinfo();


enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
class Account
{
private:
	int id;
	int money;
	char* name;
public:
	Account(const int id, int money, const char* name);
	Account(Account& copy);
	void DepositMoney(int money);
	int withdrawalMoney(int money);
	int GetId() const;
	void ShowAllInfo() const;
	~Account();

};
Account* arr[];
int arrNum;
