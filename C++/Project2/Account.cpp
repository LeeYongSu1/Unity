#include "Account.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

Account accarr[100];	//Account������ ���� �迭
int accNum = 0; //����� Account��

void ShowMenu(void)
{
	cout << "-------Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}
void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << endl;

	accarr[accNum].accID = id;
	accarr[accNum].balance = balance;
	strcpy_s(accarr[accNum].cusName, sizeof(accarr[accNum].cusName), name);
	accNum++;
}
void DepositMoney(void)
{
	int money;
	int id;
	cout << "[�Ա�]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i = accNum; i++)
	{
		if (accarr[i].accID = id)
		{
			accarr[i].balance += money;
			cout << "�Ա� �Ϸ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[��  ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accarr[i].accID = id)
		{
			if (accarr[i].balance < money)
			{
				cout << "�ܾ� ����" << endl;
			}

			accarr[i].balance -= money;
			cout << "��ݿϷ�" << endl << endl;
		}
	}
}
void ShowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++)
	{
		cout << "���� ID: " << accarr[i].accID << endl;
		cout << "�̸�: " << accarr[i].cusName << endl;
		cout << "�ܾ�: " << accarr[i].balance << endl;
	}
}