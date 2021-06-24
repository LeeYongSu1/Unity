#include "Prectice1.h"

int main()
{
	
	int* arr = new int[10];
	for (int i = 0; i <= 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i <= 10; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	system("resume");
	return 0;
}