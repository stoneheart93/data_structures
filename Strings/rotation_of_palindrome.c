#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char text[100];
char str[100];

int min(int a, int b)
{
	return (a < b)? a : b;
}

char* preprocess(char* str)
{
    int N = strlen(str);
	char* ret = (char*)malloc(sizeof(char) * (2 * N + 4));
	int i = 0, index = 0;
    ret[index++] = '$';
    while(i < N)
    {
    	if(index % 2 != 0)
            ret[index++] = '#';
        else
        	ret[index++] = str[i++];
    }
    ret[index++] = '#';
    ret[index++] = '@';
    ret[index] = '\0';
    return ret;
}
int findLongestPalindromicString(char* text, int size)
{
	int N = strlen(text);
	
	int* L = (int*)calloc(N, sizeof(int)); 
 	
	int C = 1, R = 1; 
	int Mirror, i; 
	
	for (i = 2; i < N; i++) 
	{
		Mirror = 2 * C - i;
		if(i < R)
			L[i] = min(L[Mirror], R - i);

		while (text[i + 1 + L[i]] == text[i - 1 - L[i]])
			L[i]++;

		if (i + L[i] > R) 
		{
			C = i;
			R = i + L[i];
		}
	}
	for(i = 0; i < N; i++)
	{
		if(L[i] == size)
			return 1;
		else if(size < L[i])
		{
			if(size % 2 == 0 && L[i] % 2 == 0)
				return 1;
			else if(size % 2 != 0 && L[i] % 2 != 0)
				return 1;
		}		
	}
	return 0;
}

int isRotationPalindrome(char* str)
{
	int size = strlen(str);
	char* temp = (char*)malloc(sizeof(char) * (2 * size + 1));
	temp[0] = '\0';
	strcat(temp, str);
	strcat(temp, str);
	if(findLongestPalindromicString(preprocess(temp), size))
		return 1;
	else
		return 0;
}

int main()
{
	if(isRotationPalindrome("aaaad"))
		printf("Rotation of a palindrome");
	else
		printf("Not a rotation of a palindrome");
	return 0;
}
