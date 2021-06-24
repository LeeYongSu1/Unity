//
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//const int NAME_LEN = 20;
//
//enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//enum {LEVEL_A = 7, LEVEL_B = 5, LEVEL_C = 3};
//enum {NOMAL = 1, CREDIT = 2};
//
//
///*
// * Ŭ���� �̸�: Account
// * Ŭ���� ����: Entity Ŭ����
// */
//
//class Account
//{
//private:
//	int accID;
//	int balance;
//	char* cusName;
//
//public:
//	Account(int ID, int money, const char* name);
//	Account(const Account& ref);
//
//	int GetAccID() const;
//	virtual void Deposit(int money);
//	int Withdraw(int money);
//	void ShowAccInfo() const;
//	~Account();
//};
//
//Account::Account(int ID, int money, const char* name)
//	: accID(ID), balance(money)
//{
//	cusName = new char[strlen(name) + 1];
//	strcpy_s(cusName, strlen(name) + 1, name);
//}
//
//Account::Account(const Account& ref)
//	: accID(ref.accID), balance(ref.balance)
//{
//	cusName = new char[strlen(ref.cusName) + 1];
//	strcpy_s(cusName, strlen(ref.cusName) + 1, ref.cusName);
//}
//
//int Account::GetAccID() const { return accID; }
//
//void Account::Deposit(int money)
//{
//	balance += money;
//}
//
//int Account::Withdraw(int money)
//{
//	if (balance < money)
//		return 0;
//
//	balance -= money;
//	return money;
//}
//
//void Account::ShowAccInfo() const
//{
//	cout << "����ID: " << accID << endl;
//	cout << "��  ��: " << cusName << endl;
//	cout << "��  ��: " << balance << endl;
//}
//
//Account::~Account()
//{
//	delete[]cusName;
//}
//
//class NormalAccount : public Account
//{
//private:
//	int interest;
//public:
//	NormalAccount(int ID, int money, const char* name, int Rest) : Account(ID, money, name), interest(Rest){}
//
//	virtual void Deposit(int money)
//	{
//		Account::Deposit(money);
//		Account::Deposit(money * (interest / 100.0));//���� �߰�
//	}
//
//};
//
//class HightCreditAccount : public NormalAccount
//{
//private:
//	int spRest;
//public:
//	HightCreditAccount(int ID, int money, const char* name, int Rest, int spRest) : NormalAccount(ID, money, name, Rest), spRest(spRest){}
//
//	virtual void Deposit(int money)
//	{
//		NormalAccount::Deposit(money);
//		HightCreditAccount::Deposit(int(money * (spRest / 100.0)));
//	}
//};
//
//class AccountHandler
//{
//private:
//	Account* accArr[100];
//	int accNum;
//
//public:
//	AccountHandler();
//	void ShowMenu(void) const;
//	void MakeAccount(void);
//	void DepositMoney(void);
//	void WithdrawMoney(void);
//	void ShowAllAccInfo(void) const;
//	void MakeNoralAccount();
//	void MakeCreDitAccount();
//	~AccountHandler();
//};
//
//void AccountHandler::ShowMenu(void) const
//{
//	cout << "-----Menu------" << endl;
//	cout << "1. ���°���" << endl;
//	cout << "2. ��    ��" << endl;
//	cout << "3. ��    ��" << endl;
//	cout << "4. �������� ��ü ���" << endl;
//	cout << "5. ���α׷� ����" << endl;
//}
//
//void AccountHandler::MakeAccount(void)
//{
//	int sel;
//	cout << "[������������]" << endl;
//	cout << "1. ���뿹�ݰ��� ";
//	cout << "2. �ſ�ŷڰ���" << endl;
//	cin >> sel; cout << endl;
//	switch (sel)
//	{
//		case NOMAL:
//			MakeNoralAccount();
//			break;
//		case CREDIT:
//			MakeCreDitAccount();
//			break;
//		default:
//			break;
//	}
//
//}
//
//void AccountHandler::MakeNoralAccount()
//{
//	int id;
//	char name[10];
//	int money;
//	int interest;
//	cout << "[���뿹�ݰ��� ����]" << endl;
//	cout << "����ID:"; cin >> id; cout << endl;
//	cout << "�� ��:"; cin >> name; cout << endl;
//	cout << "�Աݾ�:"; cin >> money; cout << endl;
//	cout << "������:"; cin >> interest; cout << endl;
//
//	accArr[accNum++] = new NormalAccount(id, money, name, interest);
//}
//void AccountHandler::MakeCreDitAccount()
//{
//	int id;
//	char name[10];
//	int money;
//	int interest;
//	int level;
//
//	cout << "[�ſ�ŷڰ��� ����]" << endl;
//	cout << "����ID:"; cin >> id; cout << endl;
//	cout << "�� ��:"; cin >> name; cout << endl;
//	cout << "�Աݾ�:"; cin >> money; cout << endl;
//	cout << "������:"; cin >> interest; cout << endl;
//	cout << "���: "; cin >> level; cout << endl;
//
//	switch (level)
//	{
//	case 1:
//		accArr[accNum++] = new HightCreditAccount(id, money, name, interest, LEVEL_A);
//	case 2:
//		accArr[accNum++] = new HightCreditAccount(id, money, name, interest, LEVEL_B);
//	case 3:
//		accArr[accNum++] = new HightCreditAccount(id, money, name, interest, LEVEL_C);
//	default:
//		break;
//	}
//
//	
//}
//
//void AccountHandler::DepositMoney(void)
//{
//	int money;
//	int id;
//	cout << "[��    ��]" << endl;
//	cout << "����ID: ";	cin >> id;
//	cout << "�Աݾ�: ";	cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetAccID() == id)
//		{
//			accArr[i]->Deposit(money);
//			cout << "�ԱݿϷ�" << endl << endl;
//			return;
//		}
//	}
//	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
//}
//
//void AccountHandler::WithdrawMoney(void)
//{
//	int money;
//	int id;
//	cout << "[��    ��]" << endl;
//	cout << "����ID: ";	cin >> id;
//	cout << "��ݾ�: ";	cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetAccID() == id)
//		{
//			if (accArr[i]->Withdraw(money) == 0)
//			{
//				cout << "�ܾ׺���" << endl << endl;
//				return;
//			}
//
//			cout << "��ݿϷ�" << endl << endl;
//			return;
//		}
//	}
//	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
//}
//
//AccountHandler::AccountHandler() : accNum(0)
//{  }
//
//void AccountHandler::ShowAllAccInfo(void) const
//{
//	for (int i = 0; i < accNum; i++)
//	{
//		accArr[i]->ShowAccInfo();
//		cout << endl;
//	}
//}
//
//AccountHandler::~AccountHandler()
//{
//	for (int i = 0; i < accNum; i++)
//		delete accArr[i];
//}
//
//
///*
// * ��Ʈ�� Ŭ���� AccountHandler �߽����� ����� main �Լ�
// */
//
//int main(void)
//{
//	AccountHandler manager;
//	int choice;
//
//	while (1)
//	{
//		manager.ShowMenu();
//		cout << "����: ";
//		cin >> choice;
//		cout << endl;
//
//		switch (choice)
//		{
//		case MAKE:
//			manager.MakeAccount();
//			break;
//		case DEPOSIT:
//			manager.DepositMoney();
//			break;
//		case WITHDRAW:
//			manager.WithdrawMoney();
//			break;
//		case INQUIRE:
//			manager.ShowAllAccInfo();
//			break;
//		case EXIT:
//			return 0;
//		default:
//			cout << "Illegal selection.." << endl;
//		}
//	}
//
//	return 0;
//}