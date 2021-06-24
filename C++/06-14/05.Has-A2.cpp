#include "Default.h"

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char * title, const char * isbn, int price) : price(price)
	{
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy_s(this->title, strlen(title) + 1, title);
		strcpy_s(this->isbn, strlen(isbn) + 1, isbn);
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;
public:
	EBook(const char* title, const char* isbn, int price, const char* DRMKey): Book(title, isbn, price)
	{
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy_s(this->DRMKey, strlen(DRMKey) + 1, DRMKey);
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout << "인증키:" << DRMKey << endl;
	}
	~EBook()
	{
		delete[]DRMKey;
	}
};

int main6(void)
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "asdf2adelkj");
	ebook.ShowEBookInfo();
	return 0;
}