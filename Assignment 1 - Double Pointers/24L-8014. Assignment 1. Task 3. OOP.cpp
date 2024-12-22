#include <iostream>

using namespace std;

int** old_array(int& rows, int& columns)
{
	int** matrix = new int*[rows];
	for (int i=0;i<rows;i++)
	{
		*(matrix+i) = new int[columns];
	}
	

    int values[5][6] = {
        {2, 3, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 0},
        {1, 1, 1, 2, 0, 2},
        {5, 0, 0, 0, 10, 0}
    };

 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            *(*(matrix+i)+j) = values[i][j];
        }
    }

 
    cout << "Matrix values:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << *(*(matrix+i)+j) << " ";
        }
        cout << endl;
    }

    return matrix;
}


void ModifiedArray(int** matrix, int& rows, int& columns)
{
	int* rowsize = new int[rows];
	for (int i=0; i<rows; i++)
	{
		int count = 0;
		for (int j=0; j<columns; j++)
		{
			if (*(*(matrix+i)+j) !=0)
			{
				count++;
			}
		}
		rowsize[i] = count;
	}
	
	int** newArray = new int*[rows];
	for (int i=0; i<rows;i++)
	{
		*(newArray+i) = new int[rowsize[i]];
	}
	for (int i=0; i<rows;i++)
	{
		int index=0;
		for (int j=0; j<columns;j++)
		{
			if (*(*(matrix+i)+j) != 0)
			{
				*(*(newArray+i)+index++) = *(*(matrix+i)+j);
			}
		}
	}
	
	cout<<"Newly Modified Array is: "<<endl;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<rowsize[i]; j++)
		{
			cout << *(*(newArray+i)+j)<<' ';
		}
		cout<<endl;
	}
	
}

void deallocateMemory(int** matrix, int& rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];  
    }
    delete[] matrix; 
}


int main()
{
	int rows, columns;
	rows=5;
	columns=6;
//	cout<<"Enter the Number of Rows: "<<endl;
//	cin>>rows;
//	cout<<"\nEnter the Number of Columns: "<<endl;
//	cin>>columns;
	int** matrix = old_array(rows, columns);
	ModifiedArray(matrix, rows, columns);
	deallocateMemory(matrix, rows);

}
