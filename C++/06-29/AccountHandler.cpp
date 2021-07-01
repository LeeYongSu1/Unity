#include "AccountHandler.h"
#include "Default.h"
#include "InterRateAccount.h"

AccountHandler::AccountHandler() :accNum(0) {}

void AccountHandler::ShowMenu(void)
{
	cout << "=====MENU=====" << endl;
	cout << "1. ���°���" << endl;
	cout << "2.�� ��" << endl;
	cout << "3.�� ��" << endl;
	cout << "4.�������� ��ü ���" << endl;
	cout << "5. ���α׷� ����	" << endl;
}
void AccountHandler::MakeAccount()
{
	/*int id;
	char name[20];
	int money;
	cout << "[���°���]" << endl;
	cout << "���� ���̵� �Է�: "; cin >> id;
	cout << "�̸� �Է�: "; cin >> name;
	cout << "���� �ݾ� �Է�: "; cin >> money;*/


	/*accArr[accNum++] = new Account(id, money, name);*/
	int sel;
	cout << "[���� ���� ����]" << endl;
	cout << "1.���뿹�ݰ��� ";
	cout << "2.Ư������ " << endl;
	cout << "����: ";
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

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��  ��: ";	cin >> name;
	cout << "�Աݾ�: ";	cin >> balance;
	cout << "������: ";	cin >> interRate;
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

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��  ��: ";	cin >> name;
	cout << "�Աݾ�: ";	cin >> balance;
	cout << "������: ";	cin >> interRate;
	cout << "�ſ���(1toA, 2toB, 3toC): ";	cin >> creditLevel;
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
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Ա� �ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetId() == id)
		{
			accArr[i]->DepositMoney(money);
			cout << "�Ա� �Ϸ�" << endl << endl;
			return;
		}
	}
	cout << "���̵� ��ġ���� �ʽ��ϴ�." << endl;
}

void AccountHandler::WithdrawMonay()
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "ID�Է�"; cin >> id;
	cout << "��� �ݾ� �Է�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetId() == id)
		{
			if (accArr[i]->WithdrawMoney(money) <= 0)
			{
				cout << "�ܾ� ����" << endl << endl;
				return;
			}
			cout << "��ݿϷ�" << endl;
			return;
		}
	}
	cout << "ID�� ��ġ���� �ʽ��ϴ�." << endl << endl;
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