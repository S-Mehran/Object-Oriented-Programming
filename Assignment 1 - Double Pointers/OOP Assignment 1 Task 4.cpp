#include <iostream>
#include <cctype>
using namespace std;




int** fillArray(int** matrix, int& rows, int* colsize)
{
	cout<<"Enter values "<<endl;
	int inputValue;
	for (int i=0; i<rows;i++)
	{
		for (int j=0; j<colsize[i];j++)
		{
			cout<<"\nRow No: "<<i<<" Column No: "<<j<<endl;
			cin>>inputValue;
			if (inputValue >= 0)
			{
			*(*(matrix+i)+j) = inputValue;				
			}
			else
			{
				cout<<"Negative Values are not Allowed"<<endl;
			}
		}
	}
	
	for (int i=0;i<rows;i++)
	{
		for (int j=0; j<colsize[i]; j++)
		{
			cout<<*(*(matrix+i)+j)<<' ';
		}
		cout<<endl;
	}
	
	
	return matrix;

}

int* TwoDimToOneDim(int** matrix, int& rows, int* colsize, int& size)
{
//	int size=0;
//	for (int i=0; i<rows;i++)
//	{
//		size += rows*colsize[i];
//
//	}
//
//	
	int* array = new int[size];
	int index = 0;
	for (int i=0; i<rows;i++)
	{
		for (int j=0; j<colsize[i];j++)
		{
			*(array+index++) = *(*(matrix+i)+j);
		}
	}
	return array;
}

int* sortArr(int* array, int& size)
{
	for (int i=0; i<size-1; i++)
	{
		for (int j=0; j<size-i-1;j++)
		{
			if (*(array+j) > *(array+j+1))
			{
				int temp = *(array+j);
				*(array+j) = *(array+j+1);
				*(array+j+1) = temp;
			}
		}
	}
	
	return array;
}



void showArr(int* array, int& size)
{
	for (int i=0; i<size;i++)
	{
		cout<< *(array+i)<<' ';
	}
}

void deallocateArrays(int* array, int** matrix, int rows) {
    delete[] array;
    array = nullptr; 
    
    
    
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i]; 
    }


    delete[] matrix;
    matrix = nullptr; 
}



void deallocate2DArray() {

}

int main()
{
	int rows;
	cout<<"Enter the number of rows: "<<endl;
	cin>>rows;
	int* colsize = new int[rows];
	for (int i=0; i<rows;i++)
	{
		cout<<"Enter the columns in Row "<<i<<endl;
		cin>>colsize[i];
	}

	int** matrix = new int*[rows];
	for (int i=0;i<rows;i++)
	{
		*(matrix + i) = new int[colsize[i]];
	}
	int** matrix_new = fillArray(matrix, rows, colsize);
// Size
	int size=0;

	for (int i=0; i<rows;i++)
	{
		size += colsize[i];

	}
	int* convertedArray = TwoDimToOneDim(matrix_new, rows, colsize, size);
	

	cout<<"Array After being converted to 1D array: "<<endl;
	showArr(convertedArray, size);
	cout<<"\nSorted Array is as follows: "<<endl;
	int* sortedArray = sortArr(convertedArray, size);
	showArr(convertedArray, size);
	
	
	deallocateArrays(convertedArray, matrix_new, rows);
	
	    
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i]; 
    }


    delete[] matrix;
    matrix = nullptr; 

	
	
}
