//#include "Default.h"
//
//int StoI(char* str)//���ڿ� �� ���� ������ ��󳻴� �Լ�
//{
//	int len = strlen(str);
//	int num = 0;
//	int expNum = 0;
//	//���ڿ� ���̰� ���� 0�� �ƴϰ� ���� 0�̸� ����ó��
//	if (len != 0 && str[0] == '0')
//		throw 0;
//
//	//���� ĳ���Ͱ� �ƴϸ� ����ó��
//	for (int i = 0; i < len; i++)
//	{
//		if (str[i] < '0' || str[i]>'9')
//			throw str[i];
//
//		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
//		//���ڿ��� ������ ��ȯ�ϴ� �Լ� �� ���� ������ ���ؼ��� �����ϵ��� ���� �Ǿ���.
//	}
//	return num;
//}
//
//int main(void)
//{
//	char str1[100];
//	char str2[200];
//	int expNum;
//
//	while (true)
//	{
//		cout << "�� ���� ���� �Է�: ";
//		cin >> str1 >> str2;
//
//		try
//		{
//			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
//			break;
//		}
//		catch (char ch)
//		{
//			if (expNum == 3)
//				break;
//			cout << "����" << ch << "�� �ԷµǾ����ϴ�." << endl;
//			cout << "���Է� �����մϴ�." << endl << endl;
//			expNum++;
//		}
//		catch (int expn)
//		{
//			if (expNum == 3)
//				break;
//
//			if (expn == 0)
//			{
//				cout << "0���� �����ϴ� ���ڴ� �ԷºҰ�." << endl;
//				expNum++;
//			}
//			else
//			{
//				cout << "�������� �Է��� �̷�������ϴ�." << endl;
//				expNum++;
//			}
//				
//
//			cout << "���Է� �����մϴ�." << endl;
//		}
//	}
//	cout << "���α׷��� �����մϴ�." << endl;
//
//	return 0;
//}