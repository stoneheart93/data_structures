#include<stdio.h>
#include<string.h>

int countToMake0lternate(char* str)
{
    int result = 0;
    int i;
    int len = strlen(str);
    
    for(i=0; i < len -1; i++)
	{
	    if (str[i] == str[i+1])
            result++; 
	}
    return result;
}

int main()
{
    char str[10];
    scanf("%s", str);
    printf("%d", countToMake0lternate(str));
    return 0;
}
