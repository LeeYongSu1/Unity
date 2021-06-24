//#include "Default.h"
//
//class Point
//{
//private:
//	int xpos, ypos;
//public:
//	Point(int x = 0, int y = 0): xpos(x), ypos(y)
//	{}
//	friend ostream& operator<<(ostream& os, const Point& pos);
//};
//ostream& operator<<(ostream& os, const Point& pos)
//{
//	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
//	return os;
//}
////C# listdml wjdcp
//typedef Point* POINT_PTR;
//
//class BoundCheckPointArray
//{
//private:
//	POINT_PTR* arr;	//멤버 변수로 포인터 클래스 객체 포인터를 선언
//	int arrlen;//배열의 길이값
//	//복사 생성자 대입연산자 오버로딩 함수를 이곳에 선언해서 데이터의 유일성을 확보한다.
//	BoundCheckPointArray(const BoundCheckPointArray& arr){}
//	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) {}
//	//즉 이 객체가 복사가 되지 않게 막는다.
//public:
//	BoundCheckPointArray(int len) :arrlen(len)
//	{
//		arr = new POINT_PTR[len];
//	}
//
//	POINT_PTR& operator[](int idx)//멤버함수로 선언해야 함 배열 인덱스 함수라서
//	{
//		if (idx < 0 || idx >= arrlen)//배열 경계 검사
//		{
//			cout << "Array index out of bound exception"<<endl;
//			exit(1);
//		}
//
//		return arr[idx];
//	}
//
//	POINT_PTR operator[](int idx) const//const 배열연산자 함수 오버로딩
//	{
//		if (idx < 0 || idx >= arrlen)
//		{
//			cout << "Array index out of bound exception" << endl;
//			exit(1);
//		}
//
//		return arr[idx];
//	}
//
//	int GetArrlen()const//멤버 변수에 접근 하기 위한 함수
//	{
//		return arrlen;
//	}
//	~BoundCheckPointArray()
//	{
//		delete[] arr;
//	}
//};
//
//int main(void)
//{
//	BoundCheckPointArray arr(3);
//	//arr[0] = new Point(3,4); - 동적 할당 후에 delete
//	//arr[0] = Point(3, 4);
//	////arr[1] = Point(5, 6); 원본
//	//arr.operator[](1) = Point(5, 6);
//	//arr[1] = Point(5, 6);
//	//arr[2] = Point(7, 8);
//
//	arr[0] = new Point(3, 4);
//	arr[1] = new Point(5, 6);
//	arr[2] = new Point(7, 8);
//
//	for (int i = 0; i < arr.GetArrlen(); i++)
//	{
//		//cout << arr[i];
//		cout << *(arr[i]);
//	}
//	for (int i = 0; i <3; i++)
//	{
//		delete arr[i];
//	}
//
//
//	return 0;
//}
