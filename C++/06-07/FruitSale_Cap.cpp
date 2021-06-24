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
//	//�̴ϼ� ������ ��� ����� ���ÿ� �߰�
//{
//	//myMoney = money; ���� �� ���߿� �ʱ�ȭ
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
//	cout << "���� �ܾ�: " << myMoney << endl;
//	cout << "��� ����: " << numOfApples << endl << endl;
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
//	cout << "���� �Ǹ����� ��Ȳ" << endl;
//	seller.ShowSalesResult();
//	cout << "���� �������� ��Ȳ" << endl;
//	buyer.ShowBuyResult();
//
//	
//
//	return 0;
//}