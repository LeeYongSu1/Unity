#pragma once
#include "Account.h"

class AccountHandler
{
private:
	Account* accArr[100];   // Account ������ ���� �迭
	int accNum;        // ����� Account ��
public:
	AccountHandler();
	void ShowMenu(void);       // �޴����
	void MakeAccount(void);    // ���°����� ���� �Լ�
	void DepositMoney(void);       // ��    ��
	void WithdrawMoney(void);      // ��    ��
	void ShowAllAccInfo(void);     // �ܾ���ȸ
	~AccountHandler();
};