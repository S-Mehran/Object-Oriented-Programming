#include <iostream>
using namespace std;


class Employee
{
	protected:
	int id;
	string name;
	
	public:
		Employee(int id, string name): id(id), name(name) {}
		
		virtual void displayInfo() = 0;
		
		virtual double calculateSalary()
		{
			double baseSalary = 30000;
		}
		
		virtual ~Employee() 
		{
			cout<<"Virtual Destructor"<<endl;
		}
};


class Manager: virtual public Employee
{
	protected:
	int numTeams;
	
	public:
		Manager(int id, string name, int numTeams): Employee(id, name), numTeams(numTeams) {}
		
		
		void displayInfo()
		{
			cout<<"ID: "<<id<<"\t"
			<<"Name: "<<name<<"\t"
			<<"Number of Teams: "<<numTeams<<endl;
		}
		
		double calculateSalary()
		{
			double salary = numTeams*2000;
			return salary;
		}
		
		
		void planProject()
		{
			cout<<"Each Team's Responsibilities are Planned"<<endl;
		}
};


class Engineer: virtual public Employee
{
	protected:
	int numProjects;
	
	public:
		Engineer(int id, string name, int num): Employee(id, name), numProjects(num) {}
		
		void displayInfo()
		{
			cout<<"ID: "<<id<<"\t"
			<<"Name: "<<name<<"\t"
			<<"Number of Projects: "<<numProjects<<endl;
		}
		
		double calculateSalary()
		{
			double salary = numProjects*3000;
			return salary;
		}
		
		
		void writeCode()
		{
			cout<<"There are 25 Engineering Projects in the department as of now"<<endl;
		}
		
};


class Intern: public Engineer
{
	double stipend;
	
	public:
		Intern(int id, string name, int num, double stipend): Employee(id, name), Engineer(id, name, num), stipend(stipend) {}
		
		
		void displayInfo()
		{
			Engineer::displayInfo();
			cout<<"Stipend: "<<stipend<<endl;
		}
};


class SeniorManager: public Manager
{
	double bonus;
	
	public:
		SeniorManager(int id, string name, int numTeams, double bonus): Employee(id, name), Manager(id, name, numTeams), bonus(bonus)  {}
		
		
		void displayInfo()
		{
			Manager::displayInfo();
			cout<<"Bonus: "<<bonus<<endl;
		}
		
		double calculateSalary() 
		{
			double salary = Manager::calculateSalary()+bonus;
			return salary;
		}
};


class dualRoleEmployee: public Engineer, public Manager
{
	public:
		dualRoleEmployee(int id, string name, int numTeams, int numProjects): Employee(id, name), Manager(id, name, numTeams), Engineer(id, name, numProjects) {}
		
		
	void displayInfo()
	{
		cout<<"ID: "<<id<<"\t"
		<<"Name: "<<name<<"\t"
		<<"Number of Projects: "<<numProjects
		<<"\t"<<"Number of Teams: "<<numTeams<<endl;

		
	}
	
	double calculateSalary()
	{
		double salary = Manager::calculateSalary()+Engineer::calculateSalary();
		return salary;
	}
		
};


int main()
{
	Manager mgr1(1, "Ali", 3);
	Engineer engr1(2, "Faisal", 15);
	Intern intern1(3, "John", 2, 1500.0);
	SeniorManager smgr1(4, "Callister", 7, 15000);
	dualRoleEmployee dual1(5, "Harry", 6, 13);
	
	
	Employee* emp1 = &mgr1;
	Employee* emp2 = &engr1;
	Employee* emp3 = &intern1;
	Employee* emp4 = &smgr1;

	
	emp1->displayInfo();
	cout<<"Salary: "<<emp1->calculateSalary()<<endl;
	
	emp2->displayInfo();
	cout<<"Salary: "<<emp2->calculateSalary()<<endl;

	emp3->displayInfo();
	cout<<"Salary: "<<emp3->calculateSalary()<<endl;
	
	emp4->displayInfo();
	cout<<"Salary: "<<emp4->calculateSalary()<<endl;
	

	cout<<"\n========Static Binding========="<<endl; 
	mgr1.planProject();
	engr1.writeCode();
	
	
	cout<<"\n==========Dynamic Binding==========="<<endl;
	mgr1.displayInfo();
	engr1.displayInfo();
	cout<<"\n========UpCasting======="<<endl;
	Manager mgr2(6, "Daud", 4);
	Employee* emp5 = static_cast<Employee*>(&mgr2);
	emp5->displayInfo();
	
	cout<<"\n=========DownCasting========"<<endl;
	Employee* emp6 = new Engineer(7, "Usama", 7);
	Engineer* engr2 = dynamic_cast<Engineer*>(emp6);
	engr2->displayInfo();
	engr2->writeCode();
	
	
	cout<<"\n==========Virtual Inheritance==========="<<endl;
	Employee* emp8 = &dual1;	
	emp8->displayInfo();
	cout<<"Salary: "<<emp8->calculateSalary()<<endl;
		
//	dual1.displayInfo();


}

