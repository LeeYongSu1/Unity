#include "Default.h"

class Computer
{
private:
	char* owner;
public:
	Computer(const char* name)
	{
		owner = new char[strlen(name) + 1];
		strcpy_s(owner, strlen(name)+1, name);
	}
	void Calculate()
	{
		cout << "��û ������ ����մϴ�." << endl;
	}
	~Computer()
	{
		delete[]owner;
	}
};

class NotebookComp : public Computer
{
private:
	int battary;
public:
	NotebookComp(const char* name, int initChag): Computer(name), battary(initChag) {}
	void Charging() { battary += 5; }
	void UseBattary() { battary -= 1; }
	void MovingCal() 
	{
		if (GetBattaryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}

		cout << "�̵��ϸ鼭 ";
		Calculate();
		UseBattary();
	}
	int GetBattaryInfo()
	{
		return battary;
	}
	
};

class TabletNotebook : public NotebookComp
{
private:
	char* regstPenModel;
public:
	TabletNotebook(const char* name, int initChag, const char* pen) : NotebookComp(name, initChag)
	{
		regstPenModel = new char[strlen(name) + 1];
		strcpy_s(regstPenModel, strlen(name)+1, name);
	}
	void Write(const char* penInfo)
	{
		if (GetBattaryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)
		{
			cout << "��ϵ� ���� �ƴմϴ�." << endl;
			UseBattary();
		}
	}
};

int main3(void)
{
	NotebookComp nc("�̼���", 5);
	TabletNotebook tn("a- 123", 5 , "������");
	nc.MovingCal();
	

	return 0;
}