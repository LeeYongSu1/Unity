//#include "Default.h"
//class Base
//{
//public:
//	void BaseFunc() { cout << "base Function" << endl; }
//};
//
//class Derived : public Base
//{
//public:
//	void DerivedFunc() { cout << "Edrived Function" << endl; }
//};
//
//class First
//{
//public:
//	virtual void MyFunc() { cout << "First Func" << endl; }
//};
//class Second: public First
//{
//public:
//	virtual void MyFunc() { cout << "Second Func" << endl; }
//};
//class Third:public Second
//{
//public:
//	virtual void MyFunc() { cout << "Third Func" << endl; }
//};
//
//int main()
//{
//	Third* tptr = new Third();
//	Second* sptr = tptr;
//	First* fptr = sptr;
//
//	sptr->MyFunc();
//	fptr->MyFunc();
//	return 0;
//}