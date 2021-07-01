//#include "Default.h"
//
//template <typename T>
//class SimpleStaticMem
//{
//private:
//	//멤버 필드에 static이라고 선언된 변수가 있으면 멤버 변수가 아니다.
//	//멤버 변수는 생성사 호출될때 초기화 할당됨
//	static T mem;
//public:
//	void AddMem(int num) { mem += num; }
//	void ShowMem() { cout << mem << endl; }
//};
//template <typename T>//미리 선언과 동시에 할당되어 초기화 되어 있기에
//T SimpleStaticMem<T>::mem = 0;//멤버 변수가 아니다.
//
//int main(void)
//{
//	SimpleStaticMem<int> obj1;
//	SimpleStaticMem<int> obj2;
//	obj1.AddMem(2);
//	obj2.AddMem(3);
//	obj1.ShowMem();
//	SimpleStaticMem<long> obj3;
//	SimpleStaticMem<long> obj4;
//	obj3.AddMem(100);
//	obj4.ShowMem();
//
//	return 0;
//}