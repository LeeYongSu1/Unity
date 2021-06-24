#pragma once
#include "Account.h"

class AccountHandler
{
private:
	Account* accArr[100];   // Account 저장을 위한 배열
	int accNum;        // 저장된 Account 수
public:
	AccountHandler();
	void ShowMenu(void);       // 메뉴출력
	void MakeAccount(void);    // 계좌개설을 위한 함수
	void DepositMoney(void);       // 입    금
	void WithdrawMoney(void);      // 출    금
	void ShowAllAccInfo(void);     // 잔액조회
	~AccountHandler();
};