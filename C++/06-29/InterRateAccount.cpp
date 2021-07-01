#include "InterRateAccount.h"

NormalAccount::NormalAccount(int id, int money, const char* name, int rate) : Account(id, money, name), interRate(rate)
{}

void NormalAccount::DepositMoney(int money)
{
	Account::DepositMoney(money);
	Account::DepositMoney(money * (interRate / 100.0));
}



HighCreditAccount::HighCreditAccount(int id, int money, const char* name, int rate, int special):NormalAccount(id, money, name, rate), specialRate(special)
{}

void HighCreditAccount::DepositMoney(int money)
{
	Account::DepositMoney(money);
	Account::DepositMoney(money * (specialRate / 100.0));
}