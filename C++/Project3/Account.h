#pragma once

#include <iostream>
#include <cstring>

#define NAME_LEN  20 
using namespace std;
//const int NAME_LEN=20;

void ShowMenu(void);       // 메뉴출력
void MakeAccount(void);    // 계좌개설을 위한 함수
void DepositMoney(void);       // 입    금
void WithdrawMoney(void);      // 출    금
void ShowAllAccInfo(void);     // 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct
{
	int accID;      // 계좌번호
	int balance;    // 잔    액
	char cusName[NAME_LEN];   // 고객이름
} Account;