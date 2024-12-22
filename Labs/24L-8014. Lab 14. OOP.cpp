#include <iostream>
using namespace std;


template <typename T>
void compare(T a, T b)
{
	cout<<"Inputs: a = "<<a<<" b = "<<b<<endl;
	if (a == b)
	{
		cout<<"Both values are equal"<<endl;
		
	}
	else if (a > b)
	{
		cout<<"a is greater"<<endl;
		
	}
	else 
	{
		cout<<"b is greater"<<endl;
	}
	return;
}


template <typename T1, typename T2>
class Pair
{
	T1 var;
	T2 name;
	
	public:
		Pair(T1 var, T2 name): var(var), name(name) {}
		
		
		void setVar(T1 var)
		{
			this->var = var;
		}
		void setName(T2 name)
		{
			this->name = name;
		}
		T1 getVar()
		{
			return var;
		}
		T2 getName()
		{
			return name;
		}
		
		void swap()
		{		
			T1 temp = var;
			var = name;
			name =temp;
			cout<<var<<" and "<<name<<" are successfully swapped"<<endl;
		}
		
		void display()
		{
			cout<<"Display"<<endl;
			cout<<"VAR: "<<var<<endl;
			cout<<"Name: "<<name<<endl;
		}
		
		
	
};

int main()
{
	compare(1, 2);
	compare(1,1);
	compare('A', 'B');
	compare('A', 'A');
	compare("Hello", "Hello");
	compare("Hello", "World");
	compare("Abc", "Adc");
	cout<<"\nPair Class\n"<<endl;
	Pair<int, int> pair1(5, 5);
	pair1.display();
	pair1.swap();
	
	Pair<int, double> pair2(1, 4.5);
	pair2.display();
	pair2.swap();
	pair2.display();
}
