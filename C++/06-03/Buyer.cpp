#include "Default.h"
#include "Buyer.h"

void FruitByer::InitMembers(int money)
{
	myMoney = money;
	numOfApples = 0;
}
void FruitByer::BuyApples(FruitSeller& seller, int money)
{
	numOfApples += seller.SaleApples(money);
	myMoney -= money;
}
void FruitByer::ShowBuyResult()
{
	cout << "현재 잔액: " << myMoney << endl;
	cout << "사과 개수: " << numOfApples << endl << endl;
}