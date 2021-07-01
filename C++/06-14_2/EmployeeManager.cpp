#include "Default.h"

class Employee
{
private:
    char* name;
public:
    Employee(const char* _name)
    {
        name = new char[strlen(_name) + 1];
        strcpy_s(name, strlen(_name) + 1, _name);
    }
    ~Employee()
    {
        delete name;
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
    virtual int GetPay() const = 0;
    virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee
{
private:
    int salary;
public:
    PermanentWorker(const char* name, int money)
        :Employee(name), salary(money)
    {   }
    PermanentWorker(const PermanentWorker& copy)
        :Employee(copy), salary(copy.salary)
    {   }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(const char* name, int money, double ratio)
        :PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    {   }
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const
    {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(const char* name, int pay)
        :Employee(name), workTime(0), payPerHour(pay)
    {}
    void AddWorkTime(int time)
    {
        workTime += time;
    }
    int GetPay() const
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};


class EmployeeHandler // �ڵ鷯: Ŭ������ ��Ʈ���ϴ� Ŭ����
{
private:
    Employee* empList[50];
    int empNum;
public:
    EmployeeHandler() :empNum(0)
    {}
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main()
{
    //���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
    EmployeeHandler handler;

    //���� ���
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);


    //�̹� �޿� �����ؾ� �� �޿��� ����
    handler.ShowAllSalaryInfo();

    //�̹� �޿� �����ؾ� �� �޿��� ����
    handler.ShowTotalSalary();

    return 0;
}