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
//
//namespace Choice
//{
//	/*enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//
//	void Select(int choice)
//	{
//		switch (choice)
//		{
//		case MAKE:
//			
//			break;
//		case DEPOSIT:
//			
//			break;
//		case WITHDRAW:
//			
//			break;
//		case INQUIRE:
//			
//			break;
//		case EXIT:
//			return;
//		default:
//			return;
//		}
//	}*/
//}
//
//
//class Account
//{
//	int accID;      
//	int balance;    
//	char *cusName;
//public:
//	Account(int Id, int _balance, const char * _name )
//		: accID(Id), balance(_balance)
//	{
//		cusName = new char[strlen(_name) + 1];
//		strcpy_s(cusName, strlen(_name) + 1, _name);
//	}
//	int GetAccID()const {
//
//		return accID;
//	}
//	void DepositMoney(int money)
//	{
//		balance += money;
//		cout << "�Ա� �ݾ� : " << money << endl;
//		cout << "���� �ݾ� : " << balance << endl;
//	}
//	
//	int WithdrawMoney(int money) 
//	{
//		if (balance < money)
//			return 0;
//		balance -= money;
//		return money;
//	}
//	void ShowAccount() const
//	{
//		cout << "���� ID: " << accID << endl;
//		cout << "�̸�: " << cusName << endl;
//		cout << "�ܾ�: " << balance << endl;
//	}
//	
//	~Account()
//	{
//		delete []cusName;
//	}
//};
//
//Account *accArr[100];
//int accNum = 0;
//
//int main(void)
//{
//	
//	while (true)
//	{
//		ShowMenu();
//		int choice;
//		cin >> choice;
//		
//		
//		switch (choice)
//		{
//		case 1:
//			MakeAccount();
//			break;
//		case 2:
//			DepositMoney();
//			break;
//		case 3:
//			WithdrawMoney();
//			break;
//		case 4:
//			ShowAllAccInfo();
//			break;
//		case 5:
//			return 0;;
//		default:
//			break;
//		}
//		
//	}
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
//	/*accArr[accNum].accID = id;
//	accArr[accNum].balance = balance;
//	strcpy_s(accArr[accNum].cusName, sizeof(accArr[accNum].cusName), name);*/
//	accArr[accNum++] = new Account(id, balance, name);
//	
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
//		if (accArr[i]->GetAccID() == id)
//		{
//			//accArr[i].balance += money;
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
//		if (accArr[i]->GetAccID() == id)
//		{
//			if (accArr[i]->WithdrawMoney(money) == 0)
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
//		/*cout << "����ID: " << accArr[i].accID << endl;
//		cout << "��  ��: " << accArr[i].cusName << endl;
//		cout << "��  ��: " << accArr[i].balance << endl << endl;*/
//		accArr[i]->ShowAccount();
//	}
//}