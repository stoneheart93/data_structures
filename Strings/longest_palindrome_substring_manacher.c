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
void findLongestPalindromicString(char* text)
{
	int N = strlen(text);
	if(N == 0)
		return;
 	
	int* L = (int*)calloc(N, sizeof(int)); 
 	
	int C = 1, R = 1; 
	int Mirror, i; 
	int maxLPSLength = 0, maxLPSCenterPosition = 0;
	int start, end;
	
	for (i = 2; i < N; i++) 
	{
		Mirror = 2 * C - i;
		if(i < R)
			L[i] = min(L[Mirror], R - i);

		while (text[i + 1 + L[i]] == text[i - 1 - L[i]])
			L[i]++;

		if(L[i] > maxLPSLength) 
		{
			maxLPSLength = L[i];
			maxLPSCenterPosition = i;
		}

		if (i + L[i] > R) 
		{
			C = i;
			R = i + L[i];
		}
	}
	start = (maxLPSCenterPosition - maxLPSLength)/2;
	end = start + maxLPSLength - 1;
	for(i = start; i <= end; i++)
		printf("%c", str[i]);
}

int main()
{
	strcpy(str,"forgeeksskeegfor");
	findLongestPalindromicString(preprocess(str));
	return 0;
}
