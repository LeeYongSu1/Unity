//#include "AccountHandler.h"
//
//int main11(void)
//{
//	int choice;
//	AccountHandler handler;
//	while (1)
//	{
//		handler.ShowMenu();
//		cout << "¼±ÅÃ: ";
//		cin >> choice;
//		cout << endl;
//
//		switch (choice)
//		{
//		case MAKE:
//			handler.MakeAccount();
//			break;
//		case DEPOSIT:
//			handler.DepositMoney();
//			break;
//		case WITHDRAW:
//			handler.WithdrawMoney();
//			break;
//		case INQUIRE:
//			handler.ShowAllAccInfo();
//			break;
//		case EXIT:
//			return 0;
//		default:
//			cout << "Illegal selection.." << endl;
//		}
//	}
//	return 0;
//}