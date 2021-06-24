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
//	POINT_PTR* arr;	//��� ������ ������ Ŭ���� ��ü �����͸� ����
//	int arrlen;//�迭�� ���̰�
//	//���� ������ ���Կ����� �����ε� �Լ��� �̰��� �����ؼ� �������� ���ϼ��� Ȯ���Ѵ�.
//	BoundCheckPointArray(const BoundCheckPointArray& arr){}
//	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) {}
//	//�� �� ��ü�� ���簡 ���� �ʰ� ���´�.
//public:
//	BoundCheckPointArray(int len) :arrlen(len)
//	{
//		arr = new POINT_PTR[len];
//	}
//
//	POINT_PTR& operator[](int idx)//����Լ��� �����ؾ� �� �迭 �ε��� �Լ���
//	{
//		if (idx < 0 || idx >= arrlen)//�迭 ��� �˻�
//		{
//			cout << "Array index out of bound exception"<<endl;
//			exit(1);
//		}
//
//		return arr[idx];
//	}
//
//	POINT_PTR operator[](int idx) const//const �迭������ �Լ� �����ε�
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
//	int GetArrlen()const//��� ������ ���� �ϱ� ���� �Լ�
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
//	//arr[0] = new Point(3,4); - ���� �Ҵ� �Ŀ� delete
//	//arr[0] = Point(3, 4);
//	////arr[1] = Point(5, 6); ����
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
