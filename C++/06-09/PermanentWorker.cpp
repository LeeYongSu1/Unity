#include "Default.h"

class PermanentWorker
{
private:
	char* name;
	int salary;
public:
	PermanentWorker(const char* name, int money) :salary(money)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	PermanentWorker(const PermanentWorker& copy) :salary(copy.salary)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy_s(name, strlen(copy.name) + 1, copy.name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo()const
	{
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl;
	}
	~PermanentWorker()
	{
		delete[]name;
	}
};

class EmployeeHandler	//�ڵ鷯 Ŭ���� ��Ʈ�� Ŭ������ �Ѵ�. Ŭ���� �߿��� ����� ������ ���� Ŭ����
{
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler(): empNum(0){}
	void AddEmployee(PermanentWorker* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo()const
	{
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary()const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();
		}
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main7(void)
{
	EmployeeHandler handler;
	//���� ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("PARK", 2000));

	//�̹��޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	//�̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();

	return 0;
}