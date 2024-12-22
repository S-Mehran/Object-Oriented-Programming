#include <iostream>

using namespace std;

class Rectangle
{
	private:
		int length;
		int width;
		
	public:
		static int count;

	//Default Constructor
		Rectangle()
		{
			length =2;
			width = 4;
		}
		
	//Method
	void setDimensions (int length, int width)
	{
		this->length = length;
		this->width = width;
	}
	
	
	//Set Length and Width and return *this
	Rectangle& setLength(int length)
	{
		this->length = length;
		return *this;
	}
	
	Rectangle& setWidth(int width)
	{
		
		this->width = width;
		return *this;
	}
	
	//print the length and width values
	void Display()
	{
		countRectangle();
	
		cout<<"Length: "<<this->length<<endl<<"Width: "<<this->width<<endl;
	}
	
	//Increment the count
	static void countRectangle()
	{
		count++;
		cout<<"Count: "<<count<<endl;
	}
	
	int getLength() const
	{
		return length;
	}
	
	int getWidth() const
	{
		return width;
	}
		
};
int Rectangle::count=0;

int main()
{
	Rectangle obj1;
	
	
	int (Rectangle::*lenptr)() const= &Rectangle::getLength;
	int (Rectangle::*widthptr)() const = &Rectangle::getWidth;
	cout<<"Using Pointers to access Data Members"<<endl;
	cout<<"Length: "<<(obj1.*lenptr)()<<endl;
	cout<<"Width: "<<(obj1.*widthptr)()<<endl; 
	
	cout<<"After using setDimensions Method"<<endl;
	obj1.setDimensions(5,20);
	obj1.Display();
	
	cout<<"Cascaded Function Calls"<<endl;
	obj1.setLength(15).setWidth(10);
	obj1.Display();
	Rectangle obj2;
	obj2.setDimensions(1,2);
	Rectangle obj3;
	obj3.setDimensions(3,6);
	Rectangle obj4;
	obj4.setDimensions(2,4);
	Rectangle::countRectangle();
	cout<<"Count is incremented and displayed with object call"<<endl;
}
