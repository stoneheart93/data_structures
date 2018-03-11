#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare (const void* a, const void* b)
{
	return (*(char *)a - *(char *)b);
}

void printSpacesRecur(char* str, char* data, int i, int j, int len)
{
	if(i == len)
	{
		data[j] = '\0';
		printf("%s\n", data);
	}
	else
	{
		data[j] = str[i];
		printSpacesRecur(str, data, i + 1, j + 1, len);
		
		data[j] = ' ';
		data[j + 1] = str[i];
		printSpacesRecur(str, data, i + 1, j + 2, len);
	}
}

void printSpaces(char* str)
{
	int len = strlen(str);
	char* data = (char*)malloc(sizeof(char) * (2* len));
	data[0] = str[0];
	printSpacesRecur(str, data, 1, 1, len);
	free(data);
}

int main()
{
    char str[] = "ABC";  
    printSpaces(str);
    return 0;
}
