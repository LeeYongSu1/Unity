#pragma once
#include "Account.h"
class NormalAccount : public Account
{
private:
	int interRate;
public:
	NormalAccount(int id, int money, const char* name, int rate);
	virtual void DepositMoney(int money);
};

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int id, int money, const char* name, int rate, int special);
	virtual void DepositMoney(int money);
};