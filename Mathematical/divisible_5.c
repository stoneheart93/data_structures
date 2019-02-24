#include<stdio.h>

int isDivisibleBy5(char* str)
{
	int len = strlen(str);	
	return ((str[len - 1] - '0') % 5 == 0);
}
 
int main()
{
    char str[20];
	scanf("%s", str);
	if(isDivisibleBy5(str))
		printf("Divisible by 5");
	else
		printf("Not divisible");
	return 0;
}
