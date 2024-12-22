#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
	protected:
	string title;
	int id;
	
	public:
		LibraryItem(): title(""), id(0) {}

		LibraryItem(string title, int id): title(title), id(id)   {}
		virtual void displayInfo()=0;
		virtual string getType() = 0;
		
		virtual void borrowItem()
		{
			cout<<"Item has been borrowed"<<endl;
		}
		
		
		void setTitle(string title)
		{
			this->title = title;
		}
		
		string getTitle()
		{
			return title;
		}
		
		void setID(int id)
		{
		this->id = id;
		}
	int getID()
	{
		return id;
	}
		
		
};



class Book: public LibraryItem
{
	string author;

	
	public:
		Book(string title, int id, string author):  LibraryItem(title, id), author(author) {}
		
		void displayInfo() override
		{
			cout<<"Title: "<<title<<"\t"<<"ID"<<id<<"\t";
			cout<<"Author: "<<author<<endl;
		}
		
		string getType() 
		{
			return "Book";
		}
		
		void borrowItem()
		{
			cout<<"Book has been borrowed"<<endl;
		}
		
		void setAuthor()
		{
			this->author = author;
		}
		
		string getAuthor()
		{
			return author;
		}
};


class Magazine: public LibraryItem
{
	int issueNumber;
	
	public:
		Magazine(string title, int id, int issueNumber): LibraryItem(title, id), issueNumber(issueNumber) {}
		
		
		void displayInfo()
		{
			cout<<"Title: "<<title<<"\t"<<"ID"<<id<<"\t";
			cout<<"issueNumber: "<<issueNumber<<endl;
		}
		
		string getType()
		{
			return "Magazine";
		}
		
		void borrowItem()
		{
			cout<<"Magazine has been borrowed"<<endl;
		}
		
		int getIssueNumber()
		{
			return issueNumber;
		}
		
};



int main()
{
	
	cout<<"============Polymorphic Access=============="<<endl<<endl;
	LibraryItem* item1;
	Book book1("art of War", 1, "Frederick");
	item1 = &book1;
	
	item1->displayInfo();
	item1->borrowItem();
	cout<<"Get Type(): "<<item1->getType()<<endl;
	
	LibraryItem* item2;
//	item2 = new Magazine("Python", 2, 34);
	Magazine maga("Python", 2, 1234);
	item2 = &maga;
	item2->displayInfo();
	item2->borrowItem();
	cout<<"Get Type(): "<<item2->getType()<<endl;
	cout<<endl;
	
	cout<<"=========Static and Dynamic Binding============"<<endl<<endl;
	item1->borrowItem();
	Book* book2 = &book1;
	book2->borrowItem();
	item2->borrowItem();
	Magazine* magazine2 = &maga;
	magazine2->borrowItem();
	
	
	cout<<endl;
	cout<<"=========Type Casting with Static Case=========="<<endl<<endl;
	Book book3("Engineering", 3, "Callister");
	LibraryItem* item3 = static_cast<LibraryItem*>(&book3);
	item3->displayInfo();
	item3->borrowItem();
	cout<<"Get Type(): "<<item3->getType()<<endl;
	
	Magazine magazine3("Geographic", 4, 134);
	LibraryItem* item4 = static_cast<LibraryItem*>(&magazine3);
	item4->displayInfo();
	item4->borrowItem();
	cout<<"Get Type(): "<<item4->getType()<<endl;
	
	
	
}
