//#include <iostream>
//
//using namespace std;
//
//int Changer(int& num);
//int Changer2(int& num);
//void SwapPointer(int *& ptr1, int *& ptr2);
//void SwapByref2(int& ref1, int& ref2);
//int main()
//{
//	int val1 = 10;
//	int val2 = 20;
//	SwapByref2(val1, val2);
//	cout << val1 << endl;
//	cout << val2 << endl;
//
//	
//	
//
//	return 0;
//}
//
//void SwapPointer(int *&ptr1, int *&ptr2)
//{
//	int *temp = 0;
//	temp = ptr1;
//	ptr1 = ptr2;
//	ptr2 = temp;
//	
//
//	cout <<*ptr1 <<' '<<*ptr2  << endl;
//}
//void SwapByref2(int& ref1, int& ref2)
//{
//	int temp = ref1;
//	ref1 = ref2;
//	ref2 = temp;
//}
//
//int Changer(int &num)
//{	
//	return ++num;
//}
//int Changer2(int& num)
//{
//	num *= -1;
//	return num;
//}