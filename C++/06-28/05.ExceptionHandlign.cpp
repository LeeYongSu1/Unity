//#include "Default.h"
//
//int main(void)
//{
//	while(true)
//	{
//		int num1, num2;
//		cout << "두 개의 숫자 입력: ";
//		cin >> num1 >> num2;
//		try
//		{
//			if (num2 == 0)
//				throw num2;
//			cout << "나눗셈의 몫: " << num1 / num2 << endl;
//			cout << "나눗셈의 나머지: " << num1 % num2 << endl;
//			return 0;
//		}
//		catch (int expn)
//		{
//			cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
//			cout << "숫자를 다시 입력하세요." << endl;
//		}
//	}
//	
//	cout << "end of main" << endl;
//	return 0;
//}