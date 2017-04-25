#include<stdio.h>
#include<string.h>
 
int isSubSequence(char* str1, char* str2, int m, int n)
{
    if(m == 0) 
		return 1;
    if(n == 0) 
		return 0;
 
    if (str1[m-1] == str2[n-1])
        return isSubSequence(str1, str2, m-1, n-1);
 
    return isSubSequence(str1, str2, m, n-1);
}
 
int main()
{
    char str1[] = "gksrek";
    char str2[] = "geeksforgeeks";
    int m = strlen(str1);
    int n = strlen(str2);
    if(isSubSequence(str1, str2, m, n))
		printf("Subsequence");
	else
		printf("Not subsequence");
	return 0;
}
