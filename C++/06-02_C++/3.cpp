//#include <iostream>
//#include <string.h>
//#include <stdlib.h>
//
//using namespace std;
//char* MakeStrAdr(int len)
//{
//	char* str = new char[len];
//	return str;
//}
//
//int main()
//{
//	char* str = MakeStrAdr(20);
//	strcpy_s(str,strlen(), "I am so happy");
//	cout << str << endl;
//
//	delete []str;
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS    // strcpy ���� ���� ���� ������ ���� ����
//#include <stdio.h>
//#include <string.h>    // strcpy �Լ��� ���ǵ� ��� ����
//#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����
//
//int main()
//{
//    char* s1 = "hello";                      // ���ڿ� ������
//    char* s2 = malloc(sizeof(char) * 10);    // char 10�� ũ�⸸ŭ ���� �޸� �Ҵ�
//
//    strcpy(s2, s1);        // s1�� ���ڿ��� s2�� ����
//
//    printf("%s\n", s2);    // Hello
//
//    free(s2);    // ���� �޸� ����
//
//    return 0;
//}