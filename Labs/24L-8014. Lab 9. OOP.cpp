#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(const string& name, int age)
    {
    	this->name = name;
    	this->age = age;
	}
    


    string getName() const 
	{ 
		return name; 
	}
    int getAge() const 
	{ 	
		return age; 
	}


    void setName(const string& name) 
	{ 
		this->name = name; 
	}
	
    void setAge(int age) 
	{
		this->age = age; 
	}
};


class Author : public Person {
private:
    string biography;

public:
    Author(const string& name, int age, const string& bio): Person(name, age)
    {
        	biography = bio;
	}


    string getBiography() const 
	{ 
		return biography; 
	}
	
    void setBiography(const string& bio) 
	{ 
		biography = bio; 
	}
	
};


class Book {
private:
    string title;
    string ISBN;
    Author* author;  

public:
    Book(const string& title, const string& ISBN, Author* author)
    {

      	this->title = title;
       	this->ISBN = ISBN;
       	this->author = author;
	}


    string getTitle() const 
	{ 
		return title; 
	}
    string getISBN() const 
	{ 
		return ISBN; 
	}
    Author* getAuthor() const 
	{ 
		return author;
	}

    void setTitle(const string& title) 
	{ 
		this->title = title; 
	}
    void setISBN(const string& ISBN) 
	{
	 	this->ISBN = ISBN; 
	}
    void setAuthor(Author* author) 
	{
	 this->author = author; 
	}

    void displayBookInfo() const {
        cout << "Title: " << title << ", ISBN: " << ISBN
             << ", Author: " << author->getName() << endl;
    }
};


class Library {
private:
    string name;
    Book* books[100];  
    int bookCount;

public:
    Library(const string& name) : name(name), bookCount(0) {}

    void addBook(Book* book) {
        if (bookCount < 100) {
            books[bookCount++] = book;
            cout << "Book added: " << book->getTitle() << endl;
        } else {
            cout << "Library is full." << endl;
        }
    }

    void removeBook(const string& title) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i]->getTitle() == title) {
                cout << "Book removed: " << books[i]->getTitle() << endl;
                // Shift books down in the array
                for (int j = i; j < bookCount - 1; ++j) {
                    books[j] = books[j + 1];
                }
                books[--bookCount] = nullptr;
                return;
            }
        }
        cout << "Book not found: " << title << endl;
    }

    void displayLibraryCollection() const {
        cout << "Library: " << name << " Collection:" << endl;
        for (int i = 0; i < bookCount; ++i) {
            books[i]->displayBookInfo();
        }
    }
};


int main() {

    Person person("John", 45);


    Author author("John", 45, "An experienced author in literature.");


    Book book1("The Art of War", "123-456-789", &author);
    Book book2("Programming", "987-654-321", &author);


    Library library("Central Library");
    library.addBook(&book1);
    library.addBook(&book2);


    library.displayLibraryCollection();


    library.removeBook("The Art of Coding");
    library.displayLibraryCollection();

    return 0;
}

