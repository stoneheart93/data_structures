#include<stdio.h>

int isDivisibleBy25(char* str)
{
	int len;
	for(len = 0; str[len]; len++);
	
	if(len == 0)
    	return 0;
 
    if(len == 1)
    	return ((str[0] - '0') % 25 == 0);
 
	return (((str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 25 == 0);
 
}
 
// Driver code
int main()
{
    char str[20];
	scanf("%s", str);
	if(isDivisibleBy25(str))
		printf("Divisible by 25");
	else
		printf("Not divisible");
	return 0;
}
