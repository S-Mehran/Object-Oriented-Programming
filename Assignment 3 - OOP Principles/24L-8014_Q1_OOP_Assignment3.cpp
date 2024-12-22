#include <iostream>
using namespace std;

//Person class to store common info between student and faculty
class Person
{
	string name;
	int age;
	
	public:
		//constructor with initializer list
		Person(string name, int age): name(name), age(age) {}
		
		//display method
		void display()
		{
			cout<<"Name: "<<name
			<<"\t"<<"Age: "<<age<<endl;
		}

};


class Student: public Person
{
	int studentID;
	string department;
	string studyField;
	
public:
	//constructor for Person and Student
	Student(string name, int age, int id, string dept, string field): Person(name, age), studentID(id), department(dept), studyField(field) {}
	
	//display using overriding
	void display()
	{
		Person::display();
		cout<<"Student ID: "<<studentID<<"\t"
		<<"Department: "<<department<<"\t"
		<<"Field of Study: "<<studyField<<endl;
	}
	
	
};

class Faculty: public Person
{
	
	string designation;
	string AreaofExpertise;

	
	public:
		//constructor for both Faculty and Person
		Faculty(string name, int age, string des, string area): Person(name, age), designation(des), AreaofExpertise(area) {}
		
		
	void display()
	{
		cout<<"Designation: "<<designation<<"\t\t"<<"Area of Expertise: "<<AreaofExpertise<<"\t"
		<<endl;
	}
};



class TeachingAssistant: public Student, public Faculty
{
	string Qualification;
	
	public:
		//Constructor that initializes all parent classes
		TeachingAssistant(int id, string Name, int age, string dept, string field, string area, string qual):
			Student(Name, age, id, dept, field), Faculty(Name, age, "Teaching Assistant", area), Qualification(qual) {}
			
			
		//Overriding to print complete details
			void display()
			{
				cout<<"\nTeaching Assistant Information"<<endl;
				Student::display();
				Faculty::display();
				cout<<"Qualification: "<<Qualification<<endl;
			}
};


int main()
{
	TeachingAssistant ta(1, "John", 22, "Computer Science", "MSCS", "Data Structures, Data Mining", "BS Computer Science");
	TeachingAssistant ta2(2, "Ali", 25, "Data Science", "MSDS", "Machine Learning, AI, Database", "BS Artificial Intelligence");
	ta.display();
	ta2.display();
}
