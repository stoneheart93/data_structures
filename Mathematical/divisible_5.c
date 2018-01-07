#include<stdio.h>

int isDivisibleBy5(char* str)
{
	int len, i, sum = 0;
	for(len = 0; str[len]; len++);
	
	return ((str[len - 1] - '0') % 5 == 0);
}
 
// Driver code
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
