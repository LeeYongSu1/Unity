//#include "Default.h"
//
//namespace mystd
//{
//	using namespace std;
//
//	class ostream
//	{
//	public:
//		ostream& operator<<(const char* str)
//		{
//			printf("%s", str);
//			return *this;
//		}
//		ostream& operator<<(char str)
//		{
//			printf("%c", str);
//			return *this;
//		}
//		ostream& operator<<(int num)
//		{
//			printf("%d", num);
//			return *this;
//		}
//		ostream& operator<<(double e)
//		{
//			printf("%g", e);
//			return *this;
//		}
//		ostream& operator<<(ostream& (*fp)(ostream& ostm))
//		{
//			fp(*this);
//			return *this;
//		}
//	};
//	class istream
//	{
//	public:
//		istream& operator<<(const char* str)
//		{
//			
//			return *this;
//		}
//		istream& operator<<(char str)
//		{
//			printf("%c", str);
//			return *this;
//		}
//		istream& operator<<(int num)
//		{
//			printf("%d", num);
//			return *this;
//		}
//		istream& operator<<(double e)
//		{
//			printf("%g", e);
//			return *this;
//		}
//		istream& operator<<(ostream& (*fp)(ostream& ostm))
//		{
//			//fp(*this);
//			return *this;
//		}
//	};
//
//	ostream& endl(ostream& ostm)
//	{
//		ostm << "\n";
//		fflush(stdout); //버퍼 비우기
//		return ostm;
//	}
//	ostream cout;
//}
//
//
//int main(void)
//{
//	using mystd::cout;
//	using mystd::endl;
//
//	cout << "Simple String";
//	cout << endl;
//	cout << 3.14;
//	cout << endl;
//	cout << 123;
//	cout << 123 << "endl" << endl;
//	endl(cout);
//	return 0;
//}