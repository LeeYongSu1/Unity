//#include "Default.h"
//
//class First
//{
//private:
//	char* strOne;
//public:
//	First() {}
//	First(const char* str)
//	{
//		strOne = new char[strlen(str) + 1];
//	}
//	void FirstFunc()
//	{
//		cout << "FirstFunc()" << endl;
//	}
//	virtual void FirstFunc()
//	{
//		cout << "First's FirstFunc" << endl;
//	}
//	virtual ~First()
//	{
//		cout << "~First()" << endl;
//		delete[]strOne;
//	}
//};
//class Second : public First
//{
//private:
//	char* strTwo;
//public:
//	Second() : First(){}
//	Second(const char* str1, const char* str2) : First(str1)
//		{
//			strTwo = new char[strlen(str2) + 1];
//		}
//	void SecondFunc()
//	{
//		cout << "SecondFunc()" << endl;
//	}
//	virtual void SecondFunc()
//	{
//		cout << "First's SecondFunc()" << endl;
//	}
//	virtual ~Second()
//	{
//		cout << "~Second()" << endl;
//		delete[]strTwo;
//		}
//};
//
//class Third : public Second
//{
//private:
//	char* strTwo;
//public:
//	Third() : Second() {}
//	Third(const char* str1, const char* str2) : Second(str1, str2)
//	{
//		strTwo = new char[strlen(str2) + 1];
//	}
//	void SecondFunc()
//	{
//		cout << "SecondFunc()" << endl;
//	}
//	virtual void SecondFunc()
//	{
//		cout << "First's SecondFunc()" << endl;
//	}
//	virtual ~Third()
//	{
//		cout << "~Second()" << endl;
//		delete[]strTwo;
//	}
//};
//
//
////int main(void)
////{
////	
////
////	return 0;
////}