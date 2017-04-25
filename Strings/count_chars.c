#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findCount(char* str)
{
    int result = 0;
	int i, j, len;
    
	len = strlen(str);
	for(i = 0 ; i < len ; i++)
	{
	    if (i == (str[i] - 'a') || i == (str[i] - 'A'))
            result++;
	}
 
    return result;
}

int main()
{
    char* str = "ABCFG" ;
    printf("%d", findCount(str));
    return 0;
}
