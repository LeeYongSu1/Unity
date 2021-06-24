#pragma once
#include "BankingSystem.h"


	Account::Account(const int id, int money, const char* name)
		: accID(id), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy_s(cusName, strlen(name) + 1, name);
	}
	int Account::GetaccId() { return accID; }
	void Account::DepositMoney(int money)
	{
		balance += money;
	}
	int Account::WithDrawMoney(int money)
	{
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}
	void Account::ShowInfo() const
	{
		cout << "���� ID: " << accID << endl;
		cout << "�̸�: " << cusName << endl;
		cout << "�ܾ�: " << balance << endl;
	}
	Account::~Account()
	{
		delete[]cusName;
	}

	Account* accArr[100];   // Account ������ ���� �迭
	int accNum = 0;        // ����� Account ��

	void ShowMenu(void)
	{
		cout << "-----Menu------" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. ��    ��" << endl;
		cout << "3. ��    ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
	}

	void MakeAccount(void)
	{
		int id;
		char name[30];
		int balance;

		cout << "[���°���]" << endl;
		cout << "����ID: ";	cin >> id;
		cout << "��  ��: ";	cin >> name;
		cout << "�Աݾ�: ";	cin >> balance;
		cout << endl;

		accArr[accNum++] = new Account(id, balance, name);
	}

	void DepositMoney(void)
	{
		int money;
		int id;
		cout << "[��    ��]" << endl;
		cout << "����ID: ";	cin >> id;
		cout << "�Աݾ�: ";	cin >> money;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->GetaccId() == id)
			{
				accArr[i]->DepositMoney(money);
				cout << "�ԱݿϷ�" << endl << endl;
				return;
			}
		}
		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
	}

	void WithdrawMoney(void)
	{
		int money;
		int id;
		cout << "[��    ��]" << endl;
		cout << "����ID: ";	cin >> id;
		cout << "��ݾ�: ";	cin >> money;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->GetaccId() == id)
			{
				if (accArr[i]->WithDrawMoney(money) == 0)
				{
					cout << "�ܾ׺���" << endl << endl;
					return;
				}
				
					cout << "��ݿϷ�" << endl << endl;
				
				return;
			}
		}
		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
	}

	void ShowAllAccInfo(void)
	{
		for (int i = 0; i < accNum; i++)
		{
			accArr[i]->ShowInfo();
		}
	}

