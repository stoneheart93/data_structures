#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void interleavingRecur(char* str1, char* str2, char* istr, int i, int j, int ind, int len)
{
	if(ind == len)
		printf("%s\n", istr);
	
	if(i < strlen(str1))
	{
		istr[ind] = str1[i];
		interleavingRecur(str1, str2, istr, i + 1, j, ind + 1, len);
	}
	
	if(j < strlen(str2))
	{
		istr[ind] = str2[j];
		interleavingRecur(str1, str2, istr, i, j + 1, ind + 1, len);	
	}
}

void interleaving(char* str1, char* str2)
{
	int m = strlen(str1);
	int n = strlen(str2);
	char* istr = (char*)malloc(sizeof(char) * (m + n + 1));
	istr[m + n] = '\0';
    interleavingRecur(str1, str2, istr, 0, 0, 0, m + n);
	free(istr);
}

int main()
{
    char str1[] = "AC";
	char str2[] = "BD";  
    interleaving(str1, str2);
    return 0;
}
