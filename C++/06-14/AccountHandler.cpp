//#include "AccountHandler.h"
//
//AccountHandler::AccountHandler() :accNum(0)
//{}
//void AccountHandler::ShowMenu(void)
//{
//	cout << "-----Menu------" << endl;
//	cout << "1. ���°���" << endl;
//	cout << "2. ��    ��" << endl;
//	cout << "3. ��    ��" << endl;
//	cout << "4. �������� ��ü ���" << endl;
//	cout << "5. ���α׷� ����" << endl;
//}
//void AccountHandler::MakeAccount(void)
//{
//	int id;
//	char name[NAME_LEN];
//	int balance;
//
//	cout << "[���°���]" << endl;
//	cout << "����ID: ";	cin >> id;
//	cout << "��  ��: ";	cin >> name;
//	cout << "�Աݾ�: ";	cin >> balance;
//	cout << endl;
//
//	accArr[accNum++] = new Account(id, balance, name);
//}
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
//void AccountHandler::ShowAllAccInfo(void)
//{
//	for (int i = 0; i < accNum; i++)
//	{
//		accArr[i]->ShowAccInfo();
//		cout << endl;
//	}
//}
//AccountHandler::~AccountHandler()
//{
//	for (int i = 0; i < accNum; i++)
//	{
//		delete accArr[i];
//	}
//}