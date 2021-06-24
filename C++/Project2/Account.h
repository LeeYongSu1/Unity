#pragma once


using namespace std;
#define NAME_LEN 20



void ShowMenu(void);	//�޴� ���
void MakeAccount(void);	//���� ����
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct
{
	int accID;
	int balance;
	char cusName[NAME_LEN];
} Account;