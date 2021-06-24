//#include "Default.h"
//
//template <typename T>
//T Add(T num1, T num2)
//{
//	cout << "T Add(T num1, T num2)" << endl;
//	return num1 + num2;
//}
//
//template <typename T>
//T Max(T a, T b)
//{
//	return a > b ? a : b;
//}
//template <>
//char* Max(char* a, char* b)
//{
//	cout << "char* Max<char*>(char* a, char* b)" << endl;
//	return strlen(a) > strlen(b) ? a : b;
//}
//
//template <>
//const char* Max(const char* a, const char* b)
//{
//	cout << "const char* Max<char*>(char* a, char* b)" << endl;
//	return strcmp(a, b) > 0 ? a : b;
//}
//
//int Add(int num1, int num2)
//{
//	cout << "int Add(int num1, int num2)" << endl;
//	return num1 + num2;
//}
//
//double Add(double num1, double num2)
//{
//	cout << "double Add(double num1, double num2)" << endl;
//	return num1 + num2;
//}
//
//int main(void)
//{
//	//cout << Add(5, 7) << endl;
//	//cout << Add(3.5, 7.5) << endl;
//	//cout << Add<int>(5, 7) << endl;
//	//cout << Add<double>(3.5, 7.5) << endl; //함수는 자료형 당 한번씩 만 호출 되고 다음 부터 공유
//
//	cout << Max(11, 14) << endl;
//	cout << Max('T', 'Q') << endl;
//	cout << Max(3.5, 7.5) << endl;
//	cout << Max("Leeasdfasdf", "YongSu") << endl;
//
//	char str1[] = "Simple";
//	char str2[] = "Best";
//	cout << Max(str1, str2) << endl;
//
//	return 0;
//}