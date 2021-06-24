#pragma once

#include <iostream>
#include <cstring>

using namespace std;
//const int NAME_LEN=20;

void ShowMenu(void);       // �޴����
void MakeAccount(void);    // ���°����� ���� �Լ�
void DepositMoney(void);       // ��    ��
void WithdrawMoney(void);      // ��    ��
void ShowAllAccInfo(void);     // �ܾ���ȸ

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
	int accID;      // ���¹�ȣ
	int balance;    // ��    ��
	char* cusName;   // ���̸�
public:
	Account();
	Account(const int id, int money, const char* name);
	int GetaccId();
	void DepositMoney(int money);
	int WithDrawMoney(int money);
	void ShowInfo() const;
	~Account();
};
