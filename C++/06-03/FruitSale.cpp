//#include "Default.h"
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//class FruitSeller
//{
//private:
//	int APPLE_PRICE;
//	int numOfApples;
//	int myMoney;
//
//public:
//	void InitMembers(int price, int num, int money);
//	int SaleApples(int money);
//	void ShowSalesResult();
//	
//};
//
//void FruitSeller::InitMembers(int price, int num, int money)
//{
//	APPLE_PRICE = price;
//	numOfApples = num;
//	myMoney = money;
//}
//
//int FruitSeller::SaleApples(int money)
//{
//	int num = money / APPLE_PRICE;
//	numOfApples -= num;
//	myMoney += money;
//	return num;
//}
//
//void FruitSeller::ShowSalesResult()
//{
//	cout << "남은 사과: " << numOfApples << endl;
//	cout << "판매 수익: " << myMoney << endl << endl;
//}
//
//class FruitByer
//{
//	int myMoney;
//	int numOfApples;
//public:
//	void InitMembers(int money);
//	void BuyApples(FruitSeller& seller, int money);
//	void ShowBuyResult();
//	
//};
//
//void FruitByer::InitMembers(int money)
//{
//	myMoney = money;
//	numOfApples = 0;
//}
//void FruitByer::BuyApples(FruitSeller& seller, int money)
//{
//	numOfApples += seller.SaleApples(money);
//	myMoney -= money;
//}
//void FruitByer::ShowBuyResult()
//{
//	cout << "현재 잔액: " << myMoney << endl;
//	cout << "사과 개수: " << numOfApples << endl << endl;
//}
//
//int main(void)
//{
//	FruitSeller seller;
//	seller.InitMembers(1000, 20, 0);
//	FruitByer buyer;
//	buyer.InitMembers(5000);
//	buyer.BuyApples(seller, 2000);
//
//	cout << "과일 판매자의 현황" << endl;
//	seller.ShowSalesResult();
//	cout << "과일 구매자의 현황" << endl;
//	buyer.ShowBuyResult();
//
//	return 0;
//}