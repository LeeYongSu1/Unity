//#include <iostream>
//#include <cstring>
//
//using namespace std;
////const int NAME_LEN=20;
//
//void ShowMenu(void);       // 메뉴출력
//void MakeAccount(void);    // 계좌개설을 위한 함수
//void DepositMoney(void);       // 입    금
//void WithdrawMoney(void);      // 출    금
//void ShowAllAccInfo(void);     // 잔액조회
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
//		cout << "입금 금액 : " << money << endl;
//		cout << "남은 금액 : " << balance << endl;
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
//		cout << "계좌 ID: " << accID << endl;
//		cout << "이름: " << cusName << endl;
//		cout << "잔액: " << balance << endl;
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
//	cout << "1. 계좌개설" << endl;
//	cout << "2. 입    금" << endl;
//	cout << "3. 출    금" << endl;
//	cout << "4. 계좌정보 전체 출력" << endl;
//	cout << "5. 프로그램 종료" << endl;
//}
//
//void MakeAccount(void)
//{
//	int id;
//	char name[30];
//	int balance;
//
//	cout << "[계좌개설]" << endl;
//	cout << "계좌ID: ";	cin >> id;
//	cout << "이  름: ";	cin >> name;
//	cout << "입금액: ";	cin >> balance;
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
//	cout << "[입    금]" << endl;
//	cout << "계좌ID: ";	cin >> id;
//	cout << "입금액: ";	cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetAccID() == id)
//		{
//			//accArr[i].balance += money;
//			accArr[i]->DepositMoney(money);
//			cout << "입금완료" << endl << endl;
//			return;
//		}
//	}
//	cout << "유효하지 않은 ID 입니다." << endl << endl;
//}
//
//void WithdrawMoney(void)
//{
//	int money;
//	int id;
//	cout << "[출    금]" << endl;
//	cout << "계좌ID: ";	cin >> id;
//	cout << "출금액: ";	cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetAccID() == id)
//		{
//			if (accArr[i]->WithdrawMoney(money) == 0)
//			{
//				cout << "잔액부족" << endl << endl;
//				return;
//			}
//
//			
//			cout << "출금완료" << endl << endl;
//			return;
//		}
//	}
//	cout << "유효하지 않은 ID 입니다." << endl << endl;
//}
//
//void ShowAllAccInfo(void)
//{
//	for (int i = 0; i < accNum; i++)
//	{
//		/*cout << "계좌ID: " << accArr[i].accID << endl;
//		cout << "이  름: " << accArr[i].cusName << endl;
//		cout << "잔  액: " << accArr[i].balance << endl << endl;*/
//		accArr[i]->ShowAccount();
//	}
//}