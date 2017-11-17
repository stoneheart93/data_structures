#include<stdio.h>

int countChars(char* str)
{
	int count = 0, i;
    for(i = 0; str[i]; i++)
    {
    	if((i == str[i] - 'a') || (i == str[i] - 'A'))
    		count++;
	}
	return count;
}

int main()
{
    char str[20];
    scanf("%s", str);
    printf("%d", countChars(str));
	return 0;
}
