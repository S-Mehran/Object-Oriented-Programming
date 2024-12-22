#include <iostream>
using namespace std;

class Person
{
	private:
		string name;
		int age;
		
	public:
		Person(string name, int age): name(name), age(age) {}
		
		
		~Person()
		{
			cout<<"Person Destroyed"<<endl;
		}
		
		
		void setName(string name)
		{
			this->name = name; 
		}
		
		void setAge(int age)
		{
			this->age = age;
		}
		
		string getName()
		{
			return name;
		}
		int getAge()
		{
			return age;
		}
		
		
		void displayInfo()
		{
			cout<<"Name: "<<name<<"	"<<"Age: "<<age<<endl;
		}
		
};


class Student: Person
{
	string studentID;
	
	public:
	Student(string Name, int Age, string ID): Person(Name, Age), studentID(ID)  {}
	
	~Student()
	{
		cout<<"Student Destroyed"<<endl;
	}
	
	void setID(string ID)
	{
		studentID = ID;
	}
	string getID()
	{
		return studentID;
	}
	
	
	void displayInfo()
	{
		cout<<"Student ID: "<<studentID<<"	";
		Person::displayInfo();
	}
	
	
};



class School
{
	const string schoolName;
	
	School(const string& sName): schoolName(sName) {};
	
	public:
		static School getSchool(string sName)
		{
			School school1(sName);
			cout<<"School Object Created"<<endl;
	//		cout<<"schoolName: "<<schoolName<<endl;
			return school1;
		}
		
		string print()
		{
			cout<<"School Name: "<<schoolName<<endl;
			return schoolName;
		}
		

		
};


	
int main()
{
	Person person1("John", 25);
	Person person2("Alice", 21);
	
	
	Student student1(person1.getName(), person1.getAge(), "24L-8014");
	Student student2(person2.getName(), person2.getAge(), "24L-8020");
	
	
	student1.displayInfo();
	cout<<endl;
	
	
	student2.displayInfo();
	cout<<endl;
	
	
	person1.displayInfo();
	cout<<endl;
	
	
	School mySchool = School::getSchool("Fast NUCES");
	mySchool.print();
	cout<<endl;
	
	
	School school2 = School::getSchool("KTH");
	school2.print();
	cout<<endl;
}










