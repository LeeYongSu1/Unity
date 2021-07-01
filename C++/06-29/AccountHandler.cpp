#include "AccountHandler.h"
#include "Default.h"
#include "InterRateAccount.h"

AccountHandler::AccountHandler() :accNum(0) {}

void AccountHandler::ShowMenu(void)
{
	cout << "=====MENU=====" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2.입 금" << endl;
	cout << "3.출 금" << endl;
	cout << "4.계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료	" << endl;
}
void AccountHandler::MakeAccount()
{
	/*int id;
	char name[20];
	int money;
	cout << "[계좌개설]" << endl;
	cout << "계좌 아이디 입력: "; cin >> id;
	cout << "이름 입력: "; cin >> name;
	cout << "개설 금액 입력: "; cin >> money;*/


	/*accArr[accNum++] = new Account(id, money, name);*/
	int sel;
	cout << "[계좌 종류 선택]" << endl;
	cout << "1.보통예금계좌 ";
	cout << "2.특별계좌 " << endl;
	cout << "선택: ";
	cin >> sel;

	if (sel == 1)
		MakeNormalAccount();
	else
		MakeSpecialAccount();
}

void AccountHandler::MakeNormalAccount()
{
	int id;
	char name[20];
	int balance;
	int interRate;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << "이자율: ";	cin >> interRate;
	cout << endl;
	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeSpecialAccount()
{
	int id;
	char name[20];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << "이자율: ";	cin >> interRate;
	cout << "신용등급(1toA, 2toB, 3toC): ";	cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, 7);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, 4);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, 2);
	}
}

void AccountHandler::DepositMoney()
{
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금 금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetId() == id)
		{
			accArr[i]->DepositMoney(money);
			cout << "입금 완료" << endl << endl;
			return;
		}
	}
	cout << "아이디가 일치하지 않습니다." << endl;
}

void AccountHandler::WithdrawMonay()
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "ID입력"; cin >> id;
	cout << "출금 금액 입력: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetId() == id)
		{
			if (accArr[i]->WithdrawMoney(money) <= 0)
			{
				cout << "잔액 부족" << endl << endl;
				return;
			}
			cout << "출금완료" << endl;
			return;
		}
	}
	cout << "ID가 일치하지 않습니다." << endl << endl;
}

void AccountHandler::ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAllAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}