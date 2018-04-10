#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#include<stdlib.h>

void permuteRepetitionRecur(char* str, char* data, int index, int len)
{
	int i;
	if(index == len)
		printf("%s\n", data);
	else
	{
		for(i = 0; i < len; i++)
		{
			data[index] = str[i];
			permuteRepetitionRecur(str, data, index + 1, len);
		}
	}
}

void permuteRepetition(char* str)
{
	int len = strlen(str);
	char* data = (char*)malloc(sizeof(char) * (len + 1));
	data[len] = '\0';
    sort(str, str + len);
	permuteRepetitionRecur(str, data, 0, len);
	free(data);
}

int main()
{
    char str[] = "ABC";  
    permuteRepetition(str);
    return 0;
}
