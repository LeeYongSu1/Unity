//#include "Default.h"
//
//class Book
//{
//private:
//	char* title;
//	char* isbn;
//	int price;
//public:
//	Book(const char * title, const char * isbn, int price): price(price)
//	{
//		this->title = new char[strlen(title) + 1];
//		strcpy_s(this->title, strlen(title) + 1, title);
//		this->isbn = new char[strlen(isbn) + 1];
//		strcpy_s(this->isbn, strlen(isbn) + 1, isbn);
//	}
//	Book(Book& copy) :price(copy.price)
//	{
//		this->title = new char[strlen(copy.title) + 1];
//		strcpy_s(this->title, strlen(copy.title) + 1, copy.title);
//		this->isbn = new char[strlen(copy.isbn) + 1];
//		strcpy_s(this->isbn, strlen(copy.isbn) + 1, copy.isbn);
//	}
//
//	Book& operator=(const Book& ref)
//	{
//		delete[]title;
//		delete[]isbn;
//
//		this->title = new char[strlen(ref.title) + 1];
//		strcpy_s(this->title, strlen(ref.title) + 1, ref.title);
//		this->isbn = new char[strlen(ref.isbn) + 1];
//		strcpy_s(this->isbn, strlen(ref.isbn) + 1, ref.isbn);
//		price = ref.price;
//
//		return *this;
//	}
//	void ShowData()
//	{
//		cout << title << ", " << isbn << ", " << price << endl;
//	}
//	~Book()
//	{
//		delete[] title;
//		delete[] isbn;
//	}
//};
//
//class EBook : public Book
//{
//private:
//	char* DRMKey;
//public:
//	EBook(const char * title, const char * isbn, int price, const char * DRMKey):Book(title, isbn, price)
//	{
//		this->DRMKey = new char[strlen(DRMKey) + 1];
//		strcpy_s(this->DRMKey, strlen(DRMKey) + 1, DRMKey);
//	}
//	EBook(EBook& copy) : Book(copy)
//	{
//		this->DRMKey = new char[strlen(copy.DRMKey) + 1];
//		strcpy_s(this->DRMKey, strlen(copy.DRMKey) + 1, copy.DRMKey);
//	}
//	EBook& operator=(const EBook& ref)
//	{
//		Book::operator=(ref);
//		delete[]DRMKey;
//		this->DRMKey = new char[strlen(ref.DRMKey) + 1];
//		strcpy_s(this->DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
//		
//
//		return *this;
//	}
//	void ShowData()
//	{
//		Book::ShowData();
//		cout << DRMKey << endl;
//	}
//	~EBook()
//	{
//		delete[]DRMKey;
//	}
//	
//};
//
//int main(void)
//{
//	EBook b1("asdf", "123123", 5000, "asdf123");
//	EBook b2("asdf", "123123", 100, "asdf123");
//	
//	return 0;
//}