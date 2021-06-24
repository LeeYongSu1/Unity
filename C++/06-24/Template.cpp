//#include "Default.h"
//
//template <typename T1, typename T2>
//class MySimple
//{
//public:
//	void WhoAreYou()
//	{
//		cout << "size of T1: " << sizeof(T1) << endl;
//		cout << "size of T2: " << sizeof(T2) << endl;
//		cout << "<typename T1, typename T2>" << endl;
//	}
//};
//
//template<>	//비어 있으면 특정 자료형에 대해 특수화를 진행한다.	-전체 특수화
//class MySimple<int, double>
//{
//public:
//	void WhoAreYou()
//	{
//		cout << "size of T1: " << sizeof(int) << endl;
//		cout << "size of T2: " << sizeof(double) << endl;
//		cout << "<int, double>" << endl;
//	}
//};
//
//template <typename T1>	//부분특수화
//class MySimple<T1, double>
//{
//public:
//	void WhoAreYou()
//	{
//		cout << "size of T1: " << sizeof(T1) << endl;
//		cout << "size of double: " << sizeof(double) << endl;
//		cout << "<typename T1, double>" << endl;
//	}
//};
////부분 특수화, 전체 특수화 두가지 모두에 해당하면 전체특수화된 클래스 객체가 생성된다.
//int main(void)
//{
//	MySimple<char, double> obj1;
//	obj1.WhoAreYou();
//	MySimple<int, long> obj2;
//	obj2.WhoAreYou();
//	MySimple<int, double> obj3;
//	obj3.WhoAreYou();
//
//	return 0;
//}
//
//
