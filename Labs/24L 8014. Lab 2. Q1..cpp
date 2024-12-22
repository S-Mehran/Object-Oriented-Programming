#include <iostream>
#include <string>
using namespace std;

int* createStudentDatabase(int numberOfStudents) {
    int* database = new int[numberOfStudents];
    return database;
}

int getStudentMarks(int* database, int index) {
    int maxValue =0;
    int temp = -1;
	for (index=0;index<5;index++)
    {
    	if (maxValue<database[index])
    	{
    		maxValue = database[index];
    		temp =index;
   // 		cout<<temp;
    		
		}

	}

	cout<<"\n"<<temp<<": "<<maxValue<<endl;
	cout<<"Maximum Marks are: " << maxValue<<" at the index of "<< temp;
	
	return database[index];
}



int main() {
    int numberOfStudents = 5;
    int* database = createStudentDatabase(numberOfStudents);

    database[0] = 10;
    database[1] = 30;
    database[2] = 75;
    database[3] = 35;
    database[4] = 50;
    
    getStudentMarks(database, 0);

 //   cout << getStudentMarks(database, 0) << endl;



    return 0;
}


