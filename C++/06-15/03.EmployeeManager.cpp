//#include "Default.h"
//
//class Employee
//{
//private:
//    char* name;
//public:
//    
//    Employee(const char* _name)
//    {
//        name = new char[strlen(_name) + 1];
//        strcpy_s(name, strlen(_name) + 1, _name);
//    }
//    
//    ~Employee()
//    {
//        delete name;
//    }
//    void ShowYourName() const
//    {
//        cout << "name: " << name << endl;
//    }
//    virtual int GetPay() const = 0;
//    virtual void ShowSalaryInfo() const = 0;
//};
//
//class PermanentWorker : public Employee
//{
//private:
//    int salary;
//public:
//    PermanentWorker(const char* name, int money)
//        :Employee(name), salary(money)
//    {   }
//    PermanentWorker(const PermanentWorker& copy)
//        :Employee(copy), salary(copy.salary)
//    {   }
//    int GetPay() const
//    {
//        return salary;
//    }
//    void ShowSalaryInfo() const
//    {
//        ShowYourName();
//        cout << "salary: " << GetPay() << endl << endl;
//    }
//};
//
//class SalesWorker : public PermanentWorker
//{
//private:
//    int salesResult;
//    double bonusRatio;
//public:
//    SalesWorker(const char* name, int money, double ratio)
//        :PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
//    {   }
//    void AddSalesResult(int value)
//    {
//        salesResult += value;
//    }
//    virtual int GetPay() const
//    {
//        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
//    }
//    virtual void ShowSalaryInfo() const
//    {
//        ShowYourName();
//        cout << "salary: " << GetPay() << endl << endl;
//    }
//};
//namespace RISK_LEVEL
//{
//    enum{RISK_A = 30, RISK_B=20, RISK_C=10};
//}
//class ForeignSalesWorker : public SalesWorker
//{
//private:
//    const int riskPay;
//public:
//    ForeignSalesWorker(const char* name, int money, double ratio, int level) : SalesWorker(name, money, ratio), riskPay(level)
//    { }
//    int GetRiskPay()const
//    {
//        return (int)(SalesWorker::GetPay() * (riskPay / 100.0));
//    }
//    int GetPay() const
//    {
//        return SalesWorker::GetPay() + GetRiskPay();
//    }
//    void ShowSalaryInfo() const
//    {
//        ShowYourName();
//        cout << "salary: " << SalesWorker::GetPay() << endl << endl;
//        cout << "riskPay: " << GetRiskPay() << endl << endl;
//        cout << "sum: " << GetPay() << endl << endl;
//
//    }
//};
//
//
//class TemporaryWorker : public Employee
//{
//private:
//    int workTime;
//    int payPerHour;
//public:
//    TemporaryWorker(const char* name, int pay)
//        :Employee(name), workTime(0), payPerHour(pay)
//    {}
//    void AddWorkTime(int time)
//    {
//        workTime += time;
//    }
//    int GetPay() const
//    {
//        return workTime * payPerHour;
//    }
//    void ShowSalaryInfo() const
//    {
//        ShowYourName();
//        cout << "salary: " << GetPay() << endl << endl;
//    }
//};
//
//
//class EmployeeHandler // 핸들러: 클래스를 컨트롤하는 클래스
//{
//private:
//    Employee* empList[50];
//    int empNum;
//public:
//    EmployeeHandler() :empNum(0)
//    {}
//    void AddEmployee(Employee* emp)
//    {
//        empList[empNum++] = emp;
//    }
//    void ShowAllSalaryInfo() const
//    {
//        for (int i = 0; i < empNum; i++)
//            empList[i]->ShowSalaryInfo();
//    }
//    void ShowTotalSalary() const
//    {
//        int sum = 0;
//        for (int i = 0; i < empNum; i++)
//            sum += empList[i]->GetPay();
//        cout << "salary sum: " << sum << endl;
//    }
//    ~EmployeeHandler()
//    {
//        for (int i = 0; i < empNum; i++)
//            delete empList[i];
//    }
//};
//
//int main()
//{
//    //직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
//    EmployeeHandler handler;
//
//    //직원 등록
//    handler.AddEmployee(new PermanentWorker("KIM", 1000));
//    handler.AddEmployee(new PermanentWorker("LEE", 1500));
//
//    TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
//    alba->AddWorkTime(5);
//    handler.AddEmployee(alba);
//
//    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
//    seller->AddSalesResult(7000);
//    handler.AddEmployee(seller);
//
//    ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
//    fseller1->AddSalesResult(7000);
//    handler.AddEmployee(fseller1);
//    //이번 달에 지불해야 할 급여의 정보
//    handler.ShowAllSalaryInfo();
//
//    //이번 달에 지불해야 할 급여의 총합
//    handler.ShowTotalSalary();
//
//    return 0;
//}