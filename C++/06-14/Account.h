#pragma once
#include "Default.h"
const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;      // 계좌번호
	int balance;    // 잔    액
	char* cusName;   // 고객이름

public:
	Account(int ID, int money, const char* name);
	int GetAccID();
	void Deposit(int money);
	int Withdraw(int money);   // 출금액 반환, 부족 시 0
	void ShowAccInfo();
	~Account();
};
