#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void stringCount(char sentence[])
{

    int size=26;
//    int* alphabet_int = new int[size];
//    for (int i=0;i<size;i++)
//    {
//        alphabet_int[i] = i+1;
//    }
//
//    for (int i=0;i<size;i++)
//    {
//        cout<<alphabet_int[i];
//    }

    char* alphabet = new char[size] {'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    int length = strlen(sentence);

    for (int i = 0; i < length; i++)
    {
        sentence[i] = tolower(sentence[i]); 
    }

    
    
    for (int i=0; i<size; i++)
    {
        int count = 0;
        for (int j=0; j<length;j++)
        {
            if (alphabet[i] == sentence[j])
            {
                count++;
            }
          
        }
        if (count > 0)
        {
        	 cout<<alphabet[i]<<' '<<count<<endl;
		  } 
    }

delete[] alphabet;
}


int main()
{
 //   stringCount();
char sentence[80];
cout<<"Enter the String: ";
cin.getline(sentence, 80, '\n');
	stringCount(sentence);

}
