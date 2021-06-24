#pragma once

#include <iostream>
#include <cstring>

using namespace std;
//const int NAME_LEN=20;

void ShowMenu(void);       // 메뉴출력
void MakeAccount(void);    // 계좌개설을 위한 함수
void DepositMoney(void);       // 입    금
void WithdrawMoney(void);      // 출    금
void ShowAllAccInfo(void);     // 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
	int accID;      // 계좌번호
	int balance;    // 잔    액
	char* cusName;   // 고객이름
public:
	Account();
	Account(const int id, int money, const char* name);
	int GetaccId();
	void DepositMoney(int money);
	int WithDrawMoney(int money);
	void ShowInfo() const;
	~Account();
};
