#include <iostream>
#include <string>

using namespace std;

class Book
{
	private:
		string title;
		string author;
		double* revScore;
		int numbReviews;
		
	 // Private function to calculate average review score
		double AvgRevScore()
		{
			double total = 0;
			for (int i=0; i<numbReviews; i++)
			{
				total += revScore[i];
			}
			double average = total/numbReviews;
			return average;
			
		}
		
		int BookReviews()
		{
			return numbReviews;
		}

		
	public:
	 // Default constructor

		Book()
		{
			title = "";
			author = "";
			revScore = nullptr;
		}
		
		// Parameterized constructor
		Book(string booktitle, string authorname, int Ratings)
		{
			title = booktitle;
			author = authorname;
			revScore = new double[Ratings];
			numbReviews = Ratings;
		}
		
		// Another parameterized constructor for deep copy
		Book(string booktitle, string authorname, double* array, int Ratings)
		{
			title = booktitle;
			author = authorname;
			revScore = new double[Ratings];
			for (int i=0; i<Ratings; i++)
			{
				revScore[i] = array[i];
			}
			numbReviews = Ratings;
			
		}
		
		// Deep copy constructor
		Book(Book& otherObj)
		{
			title = otherObj.title;
			author = otherObj.author;
			numbReviews = otherObj.numbReviews;
			revScore = new double[numbReviews];

			for (int i=0; i<numbReviews; i++)
			{
				revScore[i] = otherObj.revScore[i];
			}
		}
		
		// Shallow copy constructor
		Book(Book& otherObj, int redundant)
		{
			title = otherObj.title;
			author = otherObj.author;
			revScore = otherObj.revScore;
			numbReviews = otherObj.numbReviews;
		}
		
		
		//Destructor
		~Book()
		{
			delete[] revScore;
			cout<<"Object Destroyed"<<endl;
		}
		
		
		// Display book details
		void Display() const
		{
			cout <<"Book Title: "<< title<<endl;
			cout<<"Author Name: "<< author <<endl;
		}
		
		// Display book details with list of reviews
		void bookDetails() const
		{
			cout<<"Title of Book: "<<title<<endl;
			cout<<"Name of Author: "<<author<<endl;
			cout<<"Review Scores for book "<<title<<" are: "<<endl;
			for (int i=0; i<numbReviews; i++)
			{
				cout<<revScore[i]<<"  ";
			}
			cout<<endl;
			cout<<"Number of Reviews: "<<numbReviews<<endl;
		}
		
		
		// Functions to Access Private Functions
		double getAverage()
		{
			return AvgRevScore();
		}
		
		int getReviews()
		{
			return BookReviews();
		}
		
		
		// Add new reviews to existing record
		void addReview(double* newArray, int sizenew)
		{
			int newSize = numbReviews+ sizenew;
			double* array1 = new double[newSize];
			for (int i=0; i<numbReviews;i++)
			{
				array1[i] = revScore[i];
			}
			
			for (int i=numbReviews; i<newSize;i++)
			{
				int j = 0;
				array1[i] = newArray[i-numbReviews];
			}
			
			delete[] revScore;
//			for (int i = 0; i<newSize;i++)
//			{
//				revScore[i] = array1[i];
//			}
			revScore = array1;
			numbReviews = newSize;

		}
};


int main()
{
	Book book1;
	Book book2;

	Book book3("Maths", "Dogar", 5);
	Book book4("Why Nations Fail", "Austin", 7);
	Book book5(book4);
	
	cout<<"\nBook 1 called using Default Constructor\n"<<endl;
	book1.Display();
	cout<<"\nBook 3 called using Parametrized Constructor\n"<<endl;
	book3.Display();
	
	cout<<"\nBook 5 called using Copy Constructor using Deep Copy\n"<<endl; 
	book5.Display();

	int size =5;
	double* book_array1 = new double[size] {2.3, 2.6, 7.8, 8.1, 5.0};
	cout<<"\nBook 6 called using Parametrized Deep copy constructor\n"<<endl; 
	Book book6("Python for Machine Learning", "Aurelion", book_array1, size);
	book6.bookDetails();
//	book4.bookDetails();

	cout<<"\nBook 7 with Copy Constructor demonstrating Deep Copy\n"<<endl;
	Book book7(book6);
	book7.bookDetails();
	
	int size2 =7;
	double* book_array2 = new double[size2] {8.3, 7.6, 7.8, 6.1, 7.1, 6.9, 7.0};
	Book book8("Engineering", "Callister", book_array2, size2);
	Book* objPtr = &book8;         //Using Pointer to Access Book functions
	cout<<"\nAverage of Ratings in Book 8 are: "<<objPtr->getAverage()<<endl;
	cout<<"\nBook Details before Adding new Reviews\n"<<endl;
	objPtr->bookDetails();
	int size3 = 3;
	double* newArray = new double[size3] {9.6, 3.0, 8.8};
	objPtr->addReview(newArray, size3);
	cout<<"\nBook Details after Adding New Reviews\n"<<endl;
	objPtr->bookDetails();
	
	
	Book book9(book6, 10);
	cout<<"\nCopy Constructor using Shallow Copy\n"<<endl;
	book9.bookDetails();

}
