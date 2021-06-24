#pragma once
#include "Default.h"
#include "Saller.h"

class FruitByer
{
	int myMoney;
	int numOfApples;
public:
	void InitMembers(int money);
	void BuyApples(FruitSeller& seller, int money);
	void ShowBuyResult();

};