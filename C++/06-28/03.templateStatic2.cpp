//#include "Default.h"
//
//template <typename T>
//class SimpleStaticMem
//{
//private:
//	//��� �ʵ忡 static�̶�� ����� ������ ������ ��� ������ �ƴϴ�.
//	//��� ������ ������ ȣ��ɶ� �ʱ�ȭ �Ҵ��
//	static T mem;
//public:
//	void AddMem(int num) { mem += num; }
//	void ShowMem() { cout << mem << endl; }
//};
//template <typename T>//�̸� ����� ���ÿ� �Ҵ�Ǿ� �ʱ�ȭ �Ǿ� �ֱ⿡
//T SimpleStaticMem<T>::mem = 0;//��� ������ �ƴϴ�.
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