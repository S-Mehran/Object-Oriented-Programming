#include <iostream>
using namespace std;


class Employee
{
	protected://protected so child classes can access salary
	int id;
	string name;
	double salary;
	
	public:
		//constructor
		Employee(int id, string name, double sal): id(id), name(name), salary(sal) {}
		
		
		//true virtual function
		virtual double calculate_payroll() = 0;
		
		virtual void display()
		{
			cout<<"ID: "<<id<<"\t"<<"Name: "<<name<<"\t"
			<<"Salary: "<<salary<<endl;
		}
};

class salaryEmployee: public Employee
{
	int overtime; //Overtime in Hours
	double tax; //Tax Percentage
	
	
	public:
		//constructor to initialize parent and itself
	salaryEmployee(int id, string name, double sal, int overtime, double tax): Employee(id, name, sal), overtime(overtime), tax(tax) {}
	
	//Function adds overtime hours and deducts tax
	double calculate_payroll()
	{
		double gross_salary = salary+(overtime*150);
		double final_salary = gross_salary-((tax/100)*gross_salary);
		return final_salary;
	}
	
	virtual void display()
	{
		cout<<"\nSalaried Employee:"<<endl;
		Employee::display();
		cout<<"Overtime (in Hours): "<<overtime<<"\t"
		<<"Tax: "<<tax<<"%"<<endl;
	}

};


class commissionEmployee: public salaryEmployee
{
	double commissionPercent; 
	double profit; //Commision will depend upon profit
	
	public:
		//constructor to initialize parent and itself
	commissionEmployee(int id, string name, double sal, int overtime, double tax, double commisionPercent, double profit):
		salaryEmployee(id, name, sal, overtime, tax), commissionPercent(commissionPercent), profit(profit)  {}
	
	
	//Payroll is calculated by adding the commision in the salary calculated by salaryEmployee function
	double calculate_payroll()
	{
		double initialSalary = salaryEmployee::calculate_payroll();
		double final_salary = initialSalary+(profit*(commissionPercent/100));
		return final_salary;
	}
	
	void display()
	{
		cout<<"\nCommissioned Employee: "<<endl;
		salaryEmployee::display();
		cout<<"Profit (in Rs.): "<<profit<<"\t"
		<<"Commission Percentage: "<<commissionPercent<<endl;
	}
};


class HourlyEmployee: public Employee
{
	int hours;
	double hourlyRate; //Payment per hour
	
	public:
		//constructor to initialize parent and itself
		HourlyEmployee(int id, string name, double sal, int hours, double hourlyRate):
			Employee(id, name, sal), hours(hours), hourlyRate(hourlyRate){}
			
			
		//Payroll is calculated by adding salary into hourly pay	
		double calculate_payroll()
		{
			double final_salary = salary + (hours*hourlyRate);
			return final_salary;
		}
		
		void display()
		{
			cout<<"\nHourly Employee: "<<endl;
			Employee::display();
			cout<<"Number of Hours Worked: "<<hours<<"\t"
			<<"Hourly Rate (in Rs.): "<<hourlyRate<<endl;
		}
};


int main()
{
	Employee* emp1 = new salaryEmployee(1, "Ahmed", 45000, 15, 5);
	Employee* emp2 = new commissionEmployee(2, "Ali", 55000, 10, 5, 2.5, 100000);
	Employee* emp3 = new HourlyEmployee(3, "Ali Ahmed", 30000, 124, 300);
	
	
	emp1->display();
	emp2->display();
	emp3->display();
	cout<<endl;
	
	cout<<"Pay Roll of Salaried Employee: "<<emp1->calculate_payroll()<<endl;
	cout<<"Pay Roll of Commissioned Employee: "<<emp2->calculate_payroll()<<endl;
	cout<<"Pay Roll of Hourly Employee: "<<emp3->calculate_payroll()<<endl;
	
}
