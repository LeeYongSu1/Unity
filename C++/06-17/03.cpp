#include "Default.h"
using namespace std;
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
//		istream& operator>>(char* str)
//		{
//			fgets(str, sizeof(str), stdin);
//			return *this;
//		}
//		istream& operator>>(char str)
//		{
//			//scanf_s();
//			return *this;
//		}
//		istream& operator>>(int num)
//		{
//			
//			scanf_s("%d",num, sizeof(int));
//			return *this;
//		}
//		istream& operator>>(double e)
//		{
//			printf("%g", e);
//			return *this;
//		}
//		istream& operator>>(istream& (*fp)(istream& ostm))
//		{
//			fp(*this);
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
//	istream cin;
//}
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{

	}
	void ShowPosition()const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream& is, Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << "," << pos.ypos << ']' << endl;
	return os;
}
istream& operator>>(istream& is, Point& pos)
{
	is >> pos.xpos >> pos.ypos;
	return is;
}


int main(void)
{
	
	Point pos1;
	cout << "x, y 좌표 순으로 입력:";
	cin >> pos1;
	cout << pos1;
	return 0;
}