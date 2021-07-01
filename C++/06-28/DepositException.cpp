//#include "Default.h"
//
//class DepositException	//�Ա�
//{
//private:
//	int reqDep;
//public:
//	DepositException(int money): reqDep(money)
//	{}
//	void ShowExceptionReason()
//	{
//		cout << "[���� �޽���: " << reqDep << "�� �Ա� �Ұ�]" << endl;
//	}
//};
//
//class WithdrawException//���
//{
//private:
//	int balance;
//public:
//	WithdrawException(int money): balance(money)
//	{}
//	void ShowExceptionReason()
//	{
//		cout << "[���� �޽���: �ܾ� " << balance << ", �ܾ׺���" << endl;
//	}
//};
//
//class Account
//{
//private:
//	char accNum[50];
//	int balance;
//public:
//	Account(const char* acc, int money) : balance(money)
//	{
//		strcpy_s(accNum, sizeof(accNum), acc);
//	}
//	void Deposit(int money) //throw(DepositException)
//	{
//		if (money < 0)
//		{
//			DepositException expn(money);
//			throw expn;
//		}
//		balance += money;
//	}
//	void Withdraw(int money) //throw (WithdrawException)
//	{
//		if (money > balance)
//			throw WithdrawException(balance);
//		balance -= money;
//	}
//	void ShowMyMoney()
//	{
//		cout << "�ܰ�: " << balance << endl << endl;
//	}
//};
//
//int main(void)
//{
//	Account myAcc("1345-13243245", 5000);
//	try
//	{
//		myAcc.Deposit(2000);
//		myAcc.Deposit(-400);
//	}
//	catch (DepositException& expn)
//	{
//		expn.ShowExceptionReason();
//	}
//	myAcc.ShowMyMoney();
//
//	try
//	{
//		myAcc.Withdraw(3500);
//		myAcc.Withdraw(4500);
//
//	}
//	catch (WithdrawException& expn)
//	{
//		expn.ShowExceptionReason();
//	}
//	myAcc.ShowMyMoney();
//
//	return 0;
//}