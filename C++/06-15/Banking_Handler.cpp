#include "Banking_Handle.h"
#include "Default.h"

NormalAccount::NormalAccount(int ID, int money, const char* name, int interest) : Account(ID, money, name), interest(interest) {}

HighCreditAccount::HighCreditAccount(int ID, int money, const char* name, int interest, int scRate) : NormalAccount(ID, money, name, interest), specialRate(scRate) {}

void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int sel;
	cout << "[������������]" << endl;
	cout << "1. ���뿹�ݰ���";
	cout << "2. �ſ�ŷڰ���" << endl;
	cout << "����:";
	cin >> sel;

	if (sel == 1)
		MakeNormalAccount();
	else
		MakeCreditAccount();

}

void AccountHandler::MakeNormalAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "���� ID:"; cin >> id; cout << endl;
	cout << "�̸�:"; cin >> name; cout << endl;
	cout << "�Ա� �ݾ�:"; cin >> balance; cout << endl;
	cout << "������:"; cin >> interRate; cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int credLevel;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "���� ID:"; cin >> id; cout << endl;
	cout << "�̸�:"; cin >> name; cout << endl;
	cout << "�Ա� �ݾ�:"; cin >> balance; cout << endl;
	cout << "������:"; cin >> interRate; cout << endl;
	cout << "�ſ���:"; cin >> credLevel; cout << endl;
	switch (credLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	default:
		break;
	}

}


void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�Աݾ�: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��ݾ�: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
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

AccountHandler::AccountHandler() : accNum(0)
{  }

void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}
