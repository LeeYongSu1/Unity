//#include "Default.h"
//
//int StoI(char* str)//문자열 중 양의 정수를 골라내는 함수
//{
//	int len = strlen(str);
//	int num = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (str[i] < '0' || str[i]>'9')
//			throw str[i];
//
//		num += (int)(pow((double)10, (len - 1) - i * (str[i] + (7 - '7'))));
//		//문자열을 정수로 변환하는 함수 단 양의 정수에 대해서만 동작하도록 정의 되었다.
//	}
//	return num;
//}
//
//int main(void)
//{
//	char str1[100];
//	char str2[200];
//
//	while (1)
//	{
//		cout << "두 개의 숫자 입력: ";
//		cin >> str1 >> str2;
//
//		try
//		{
//			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
//			break;
//		}
//		catch (char ch)
//		{
//			cout << "문자" << ch << "가 입력되었습니다." << endl;
//			cout << "재입력 진행합니다." << endl << endl;
//		}
//	}
//	cout << "프로그램을 종료합니다." << endl;
//
//	return 0;
//}