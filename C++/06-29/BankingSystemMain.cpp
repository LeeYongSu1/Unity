#include "Default.h"
#include "Account.h"
#include "AccountHandler.h"

int main(void)
{
	int choice;
	AccountHandler handler;
	while (true)
	{
		handler.ShowMenu();
		cout << "¼±ÅÃ: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			handler.MakeAccount();
			break;
		case 2:
			handler.DepositMoney();
			break;
		case 3:
			handler.WithdrawMonay();
			break;
		case 4:
			handler.ShowAllAccInfo();
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
}