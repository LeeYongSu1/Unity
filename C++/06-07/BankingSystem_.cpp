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
		cout << "계좌 ID: " << accID << endl;
		cout << "이름: " << cusName << endl;
		cout << "잔액: " << balance << endl;
	}
	Account::~Account()
	{
		delete[]cusName;
	}

	Account* accArr[100];   // Account 저장을 위한 배열
	int accNum = 0;        // 저장된 Account 수

	void ShowMenu(void)
	{
		cout << "-----Menu------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입    금" << endl;
		cout << "3. 출    금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
	}

	void MakeAccount(void)
	{
		int id;
		char name[30];
		int balance;

		cout << "[계좌개설]" << endl;
		cout << "계좌ID: ";	cin >> id;
		cout << "이  름: ";	cin >> name;
		cout << "입금액: ";	cin >> balance;
		cout << endl;

		accArr[accNum++] = new Account(id, balance, name);
	}

	void DepositMoney(void)
	{
		int money;
		int id;
		cout << "[입    금]" << endl;
		cout << "계좌ID: ";	cin >> id;
		cout << "입금액: ";	cin >> money;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->GetaccId() == id)
			{
				accArr[i]->DepositMoney(money);
				cout << "입금완료" << endl << endl;
				return;
			}
		}
		cout << "유효하지 않은 ID 입니다." << endl << endl;
	}

	void WithdrawMoney(void)
	{
		int money;
		int id;
		cout << "[출    금]" << endl;
		cout << "계좌ID: ";	cin >> id;
		cout << "출금액: ";	cin >> money;

		for (int i = 0; i < accNum; i++)
		{
			if (accArr[i]->GetaccId() == id)
			{
				if (accArr[i]->WithDrawMoney(money) == 0)
				{
					cout << "잔액부족" << endl << endl;
					return;
				}
				
					cout << "출금완료" << endl << endl;
				
				return;
			}
		}
		cout << "유효하지 않은 ID 입니다." << endl << endl;
	}

	void ShowAllAccInfo(void)
	{
		for (int i = 0; i < accNum; i++)
		{
			accArr[i]->ShowInfo();
		}
	}

