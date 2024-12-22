#include <iostream>
#include <cstring>

using namespace std;

void append(char *&word, char character, int index)
{
	int len = strlen(word);
	char* newWord = new char[len+1];
	strncpy(newWord, word, index);          
	newWord[index] = character;     
	strcpy(newWord+index+1, word+index);             
	delete[] word;  
	word = newWord;
	
}

char* concatenate(char* word1, char* word2)
{
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	char* newWord = new char[len1+len2+1];
	strcpy(newWord, word1);
	strcat(newWord, word2);
	return newWord;
}

int main()
{
	char* dynamicString = new char[6];
	strcpy(dynamicString, "Helo");
	cout<<"\nBefore Appending: "<<dynamicString;
	append(dynamicString, 'l', 3);
	cout <<"\nAfter Appending: "<< dynamicString<<endl;
	
	char* Concatenated_Word = concatenate("Hello", " World");
	cout<<Concatenated_Word;
}
