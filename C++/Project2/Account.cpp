#include "Account.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

Account accarr[100];	//Account저장을 위한 배열
int accNum = 0; //저장된 Account수

void ShowMenu(void)
{
	cout << "-------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이 름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;
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
	cout << "[입금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i = accNum; i++)
	{
		if (accarr[i].accID = id)
		{
			accarr[i].balance += money;
			cout << "입금 완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출  금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accarr[i].accID = id)
		{
			if (accarr[i].balance < money)
			{
				cout << "잔액 부족" << endl;
			}

			accarr[i].balance -= money;
			cout << "출금완료" << endl << endl;
		}
	}
}
void ShowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌 ID: " << accarr[i].accID << endl;
		cout << "이름: " << accarr[i].cusName << endl;
		cout << "잔액: " << accarr[i].balance << endl;
	}
}