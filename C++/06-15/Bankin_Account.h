#pragma once
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };
/*
 * Ŭ���� �̸�: Account
 * Ŭ���� ����: Entity Ŭ����
 */

class Account
{
private:
	int accID;
	int balance;
	char* cusName;

public:
	Account(int ID, int money, const char* name);
	Account(const Account& ref);

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};