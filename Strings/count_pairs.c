#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int countPairs(char* str)
{
    int result = 0;
    int i, j, len;
    
	len = strlen(str);
	for(i = 0 ; i < len ; i++)
	{
	    for(j = 1; (i + j) < len && j <= 26; j++)
        {
            if ((abs(str[i+j] - str[i]) == j))
                result++;
        }
    }
 
    return result;
}
 
int main()
{
    char* str = "geeksforgeeks" ;
    printf("%d", countPairs(str));
    return 0;
}
