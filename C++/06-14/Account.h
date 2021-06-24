#pragma once
#include "Default.h"
const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;      // ���¹�ȣ
	int balance;    // ��    ��
	char* cusName;   // ���̸�

public:
	Account(int ID, int money, const char* name);
	int GetAccID();
	void Deposit(int money);
	int Withdraw(int money);   // ��ݾ� ��ȯ, ���� �� 0
	void ShowAccInfo();
	~Account();
};
