#pragma once
#include "Default.h"

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money);
	int SaleApples(int money);
	void ShowSalesResult();

};