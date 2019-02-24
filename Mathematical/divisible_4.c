#include<stdio.h>

int isDivisibleBy4(char* str)
{
	int len= strlen(str);
	
	if(len == 0)
    	return 0;
 	else if(len == 1)
    	return ((str[0] - '0') % 4 == 0);
 	else
		return (((str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 4 == 0);
 
}
 
int main()
{
    char str[20];
	scanf("%s", str);
	if(isDivisibleBy4(str))
		printf("Divisible by 4");
	else
		printf("Not divisible");
	return 0;
}
