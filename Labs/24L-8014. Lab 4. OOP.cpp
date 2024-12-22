#include <iostream>
#include <string>
//#include <format>
using namespace std;

class Employee
{
	private:    //data members
		int ID;
		string name;
		double salary;
		
	public:
		Employee()       //default constructor
		{
			ID = 0;
			name = " ";
			salary = 0.0;
		}
		//parametrized constructor
		Employee(int empID, string empname, double empsalary)
		{
			ID = empID;
			name = empname;
			salary = empsalary;
		}
		
		//copy constructor
		Employee(Employee& other)
		{
			ID = other.ID;
			name = other.name;
			salary = other.salary;
		}
		
		//Overloaded constructor
		Employee(int empID, string empname)
		{
			ID = empID;
			name = empname;
			salary=0.0;
		}
		
		//Function to retrieve employee details
		void employeeInfo()
		{
			cout<<"Name of Employee with an Employee ID of "<<ID<<" is "<< name<<" and his salary is "<<salary<<endl;
//			std::string formattedString = std::format("Name of Employee with an Employee ID of {} is {} and his salary is {}", ID, name, salary);
//			
//			
//			std::cout<<formattedString<<endl;

		}
		
		//Function to increment salary
		int salaryIncrement(double Percentage)
		{
			int newSalary = salary + salary*(Percentage/100);
			salary = newSalary;
			cout<<salary<<endl;
			return salary;
		}
		
		//Destructor
		~Employee()
		{
			cout<<"Object is Destroyed"<<endl;
		}
		
		//Getters and Setters
		void setID(int empid)
		{
			ID = empid;
		}
		int getID()
		{
			return ID;
		}
		
		void setName(string empname)
		{
			name = empname;
		}
		string getName()
		{
			return name;
		}
		
		
		void setSalary(double empsal)
		{
			salary = empsal;
		}
		
		double getSalary()
		{
			return salary;
		}
		
};


int main()
{
	Employee emp1;       //default constructor
	emp1.employeeInfo();
	Employee emp2(1, "Mehran", 2500); //parameterizd constructor
	emp2.employeeInfo();
	Employee emp3(2, "Daud", 3000); //parameterizd constructor
	emp3.employeeInfo();
	
	Employee emp4(3, "Arslan");       //overloaded constructor
	emp4.employeeInfo();
	
	Employee emp5(5, "Ali", 4000);   
	Employee* objPtr;                 
	objPtr = &emp5;          //Pointer to an Object
	objPtr->employeeInfo();   
	int sal = objPtr -> salaryIncrement(15);       //Acessing Member Functions of object
	objPtr->employeeInfo();	
	
	Employee emp6;                    //Using getter and setter in emp6
	emp6.setID(6);
	emp6.setName("Saad");
	emp6.setSalary(2700);
	cout<<"Get Employee ID: "<<emp6.getID()<<endl;
	emp6.employeeInfo();
	
	Employee emp7(emp2);            //Copy constructor
	emp7.employeeInfo();
	
}
