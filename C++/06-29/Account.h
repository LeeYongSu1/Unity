#pragma once
class Account
{
private:
	int accId;
	int balance;
	char* cusName;
public:
	Account(int accId, int balance, const char* cusname);
	Account(const Account& ref);
	void ShowAllAccInfo(void) const;
	int GetId() const;
	virtual void DepositMoney(int money);
	int WithdrawMoney(int money);
	~Account();
};