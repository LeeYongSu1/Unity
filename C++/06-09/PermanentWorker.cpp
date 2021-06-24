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

class EmployeeHandler	//핸들러 클래스 컨트롤 클래스라 한다. 클래스 중에서 기능적 성격이 강한 클래스
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
	//직원 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("PARK", 2000));

	//이번달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	//이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();

	return 0;
}