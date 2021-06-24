#pragma once

#include <iostream>
#include <cstring>

#define NAME_LEN  20 
using namespace std;
//const int NAME_LEN=20;

void ShowMenu(void);       // �޴����
void MakeAccount(void);    // ���°����� ���� �Լ�
void DepositMoney(void);       // ��    ��
void WithdrawMoney(void);      // ��    ��
void ShowAllAccInfo(void);     // �ܾ���ȸ

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct
{
	int accID;      // ���¹�ȣ
	int balance;    // ��    ��
	char cusName[NAME_LEN];   // ���̸�
} Account;