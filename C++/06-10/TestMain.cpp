#include "TestHeader.h"

int main(void)
{
	int choice;

	while (true)
	{
		ShowMenu();
		cout << "¼±ÅÃ: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawalMoney();
			break;
		case INQUIRE:
			ShowAllinfo();
			break;
		case EXIT:
			return 0;
		default:
			break;
		}
	}
	for (int i = 0; i < arrNum; i++)
		delete arr[i];
	return 0;
}