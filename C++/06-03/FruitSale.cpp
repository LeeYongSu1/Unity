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
//	cout << "���� ���: " << numOfApples << endl;
//	cout << "�Ǹ� ����: " << myMoney << endl << endl;
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
//	cout << "���� �ܾ�: " << myMoney << endl;
//	cout << "��� ����: " << numOfApples << endl << endl;
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
//	cout << "���� �Ǹ����� ��Ȳ" << endl;
//	seller.ShowSalesResult();
//	cout << "���� �������� ��Ȳ" << endl;
//	buyer.ShowBuyResult();
//
//	return 0;
//}