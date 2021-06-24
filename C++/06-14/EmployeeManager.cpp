#include "Default.h"

class Employee
{
private:
	char name[100];
public:
	Employee(char* name)
	{
		strcpy_s(this->name, sizeof(name), name);
	}
	void ShowYourName() const
	{
		cout << "name" << name << endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary:
public:
	PermanentWorker(const char* name, int money): Employee(name), salary(money)
	{

	}
	int GetPay()const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " < GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0){}
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo()const
	{

	}
	void showTotalSalary()const
	{
		int sum = 0;
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	//���������� �������� ����� ��Ʈ�� Ŭ������ ��ü ����
	EmployeeHandler handler;


	//�������
	handler.AddEmployee(new PermanentWorker("kim", 1000));
	handler.AddEmployee(new PermanentWorker("Lee", 1000));
	handler.AddEmployee(new PermanentWorker("Jun", 1000));

	//�̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	//�̹� �޿� �����ؾ� �� �޿��� �� ��
	handler.showTotalSalary();

	return 0;
}