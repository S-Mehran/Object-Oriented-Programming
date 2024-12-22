#include <iostream>

using namespace std;

int** AllocateMemory(int& rows, int& columns)
{
	int** arr = new int*[rows];
	for (int i=0;i<rows;i++)
	{
		*(arr + i) = new int[columns];
	}
	
	return arr;
}

void InitializeMatrix(int** matrix, const int& rows, const int& columns)
{
	for (int i=0; i<rows;i++)
	{
		for (int j=0; j<columns;j++)
		{
			*(*(matrix+i)+j) = 0;
		}
	}
}


void DisplayMatrix(int** matrix, const int& rows, const int& columns)
{
	for (int i=0; i<rows;i++)
	{
		for (int j=0; j<columns;j++)
		{
			cout<<*(*(matrix+i)+j)<<' ';
		}
	cout<<endl;
	}
}


void DeallocateMemory(int** matrix, const int& rows)
{
	for (int i=0; i<rows; i++)
	{
		delete[] *(matrix+i);
	}
	delete[] matrix;
	
}


int main()
{
	int rows, columns;
	cout<<"Enter the Number of Rows: "<<endl;
	cin>>rows;
	cout<<"\nEnter the Number of Columns: "<<endl;
	cin>>columns;
	int** matrix = AllocateMemory(rows, columns);
	InitializeMatrix(matrix, rows, columns);
	DisplayMatrix(matrix, rows, columns);
	DeallocateMemory(matrix, rows);
}

