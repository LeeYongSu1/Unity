#pragma once
#include "Account.h"

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void);
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMonay(void);
	void ShowAllAccInfo(void);
	~AccountHandler();
protected:
	void MakeNormalAccount(void);
	void MakeSpecialAccount(void);
};