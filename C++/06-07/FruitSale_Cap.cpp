//#include <iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//class FruitSeller
//{
//private:
//	const int APPLE_PRICE;
//	int numOfApples;
//	int myMoney;
//
//public:
//	FruitSeller(int price, int num, int money);
//	int SaleApples(int money);
//	void ShowSalesResult();
//	
//};
//
//FruitSeller::FruitSeller(int price, int num, int money):
//	APPLE_PRICE(price),
//	numOfApples(num),
//	myMoney(money)
//	//이니셜 라이즈 멤버 선언과 동시에 추가
//{
//	//myMoney = money; 선언 후 나중에 초기화
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
//	FruitByer(int money);
//	void BuyApples(FruitSeller & seller, int money);
//	void ShowBuyResult();
//	
//};
//
//FruitByer::FruitByer(int money)
//: myMoney(money)
//{
//	
//	numOfApples = 0;
//}
//void FruitByer::BuyApples(FruitSeller &seller, int money)
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
//	FruitSeller seller(1000, 20, 0);
//	//FruitSeller* p_seller = new FruitSeller(1000, 20, 0);
//	FruitByer buyer(5000);
//	//FruitByer* p_buyer = new FruitByer(5000);
//
//	buyer.BuyApples(seller, 2000);
//	cout << "과일 판매자의 현황" << endl;
//	seller.ShowSalesResult();
//	cout << "과일 구매자의 현황" << endl;
//	buyer.ShowBuyResult();
//
//	
//
//	return 0;
//}