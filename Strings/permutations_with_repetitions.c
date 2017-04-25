#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare (const void* a, const void* b)
{
	return (*(char *)a - *(char *)b);
}

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
    qsort(str, len, sizeof(char), compare);
	permuteRepetitionRecur(str, data, 0, len);
	free(data);
}

int main()
{
    char str[] = "ABC";  
    permuteRepetition(str);
    return 0;
}
