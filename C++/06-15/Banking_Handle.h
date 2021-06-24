#pragma once
#include "Bankin_Account.h"

class NormalAccount : public Account
{
private:
	int interest;
public:
	NormalAccount(int ID, int money, const char* name, int interest);
};

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int ID, int money, const char* name, int interest, int scRate);
	virtual void Deposit(int money);
};

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;

public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
	void MakeNormalAccount();
	void MakeCreditAccount();
};
