//#include "Default.h"
//
//class Calculator
//{
//	int add = 0;
//	int mul = 0;
//	int min = 0;
//	int div = 0;
//public:
//	 float Add(float a, float b)
//	{
//		float num;
//		
//		num = a + b;
//		add++;
//		return num;
//	}
//	 float Min(float a, float b)
//	 {
//		 float num;
//		 int count = 0;
//		 num = a - b;
//		 min++;
//		 return num;
//	 }
//	 float Mul(float a, float b)
//	 {
//		 float num;
//		 int count = 0;
//		 num = a * b;
//		 mul++;
//		 return num;
//	 }
//	 float Div(float a, float b)
//	 {
//		 float num;
//		 int count = 0;
//		 num = a / b;
//		 div++;
//		 return num;
//	 }
//
//	 void ShowOpCount()
//	 {
//		 cout << "µ¡¼À" << add << endl;
//		 cout << "»¬¼À" << min << endl;
//		 cout << "°ö¼À" << mul << endl;
//		 cout << "³ª´°¼À" << div << endl;
//	 }
//};
//
//class Printer
//{
//private:
//	
//	char str[30];
//public:
//	void SetString(const char* s);
//	void ShowString();
//	
//};
//void Printer::SetString(const char* s) {
//
//	strcpy_s(str, sizeof(str), s);
//}
//void Printer::ShowString() {
//	cout << str << endl;
//}
//
//
//int main()
//{
//	Calculator cal;
//	Printer pnt;
//	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
//	cout << "3.2 + 2.4 = " << cal.Min(5.0, 2.4) << endl;
//	cal.ShowOpCount();
//
//	pnt.SetString("Hello");
//	pnt.ShowString();
//	pnt.SetString("World");
//	pnt.ShowString();
//	
//	system("pause");
//}