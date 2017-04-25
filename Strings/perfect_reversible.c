#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isPalindrome(char* str)
{
	int len = strlen(str);
	int i = 0, j = len - 1;
 	
	while (i < j)
    {
    	if (str[i] != str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main()
{
    char* str = "ABA" ;
    printf("%d", isPalindrome(str));
    return 0;
}
