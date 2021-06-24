//#include <iostream>
//#include <cstring>
//
//using namespace std;
////const int NAME_LEN=20;
//
//void ShowMenu(void);       // �޴����
//void MakeAccount(void);    // ���°����� ���� �Լ�
//void DepositMoney(void);       // ��    ��
//void WithdrawMoney(void);      // ��    ��
//void ShowAllAccInfo(void);     // �ܾ���ȸ
//
//enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//
//class Account
//{
//	int accID;      // ���¹�ȣ
//	int balance;    // ��    ��
//	char *cusName;   // ���̸�
//public:
//	Account(const int id, int money, const char *name)
//	: accID(id), balance(money)
//	{
//		cusName = new char[strlen(name) + 1];
//		strcpy_s(cusName, strlen(name) + 1, name);
//	}
//	int GetaccId() { return accID; }
//	void DepositMoney(int money)
//	{
//		balance += money;
//	}
//	int WithDrawMoney(int money)
//	{
//		balance -= money;
//		return money;
//	}
//	void ShowInfo() const
//	{
//		cout << "���� ID: " << accID << endl;
//		cout << "�̸�: " << cusName << endl;
//		cout << "�ܾ�: " << balance << endl;
//	}
//	~Account()
//	{
//		delete[]cusName;
//	}
//
//};
//
//	
//
//
//Account *accArr[100];   // Account ������ ���� �迭
//int accNum = 0;        // ����� Account ��
//
//int main(void)
//{
//	int choice;
//
//	while (true)
//	{
//		ShowMenu();
//		cout << "����: ";
//		cin >> choice;
//		cout << endl;
//
//		switch (choice)
//		{
//		case MAKE:
//			MakeAccount();
//			break;
//		case DEPOSIT:
//			DepositMoney();
//			break;
//		case WITHDRAW:
//			WithdrawMoney();
//			break;
//		case INQUIRE:
//			ShowAllAccInfo();
//			break;
//		case EXIT:
//			return 0;
//		default:
//			cout << "Illegal selection.." << endl;
//		}
//	}
// for (int i = 0; i < accNum; i++)
		//delete accArr[i];
//	return 0;
//}
//
//void ShowMenu(void)
//{
//	cout << "-----Menu------" << endl;
//	cout << "1. ���°���" << endl;
//	cout << "2. ��    ��" << endl;
//	cout << "3. ��    ��" << endl;
//	cout << "4. �������� ��ü ���" << endl;
//	cout << "5. ���α׷� ����" << endl;
//}
//
//void MakeAccount(void)
//{
//	int id;
//	char name[30];
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
//
//void DepositMoney(void)
//{
//	int money;
//	int id;
//	cout << "[��    ��]" << endl;
//	cout << "����ID: ";	cin >> id;
//	cout << "�Աݾ�: ";	cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetaccId()== id)
//		{
//			accArr[i]->DepositMoney(money);
//			cout << "�ԱݿϷ�" << endl << endl;
//			return;
//		}
//	}
//	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
//}
//
//void WithdrawMoney(void)
//{
//	int money;
//	int id;
//	cout << "[��    ��]" << endl;
//	cout << "����ID: ";	cin >> id;
//	cout << "��ݾ�: ";	cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetaccId() == id)
//		{
//			if (accArr[i]->WithDrawMoney(money) == 0)
//			{
//				cout << "�ܾ׺���" << endl << endl;
//				return;
//			}
//
//			
//			cout << "��ݿϷ�" << endl << endl;
//			return;
//		}
//	}
//	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
//}
//
//void ShowAllAccInfo(void)
//{
//	for (int i = 0; i < accNum; i++)
//	{
//		accArr[i]->ShowInfo();
//	}
//}