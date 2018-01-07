#include<stdio.h>

int isDivisibleBy16(char* str)
{
	int len;
	for(len = 0; str[len]; len++);
	
	if(len == 0)
    	return 0;
 
    if(len == 1)
    	return ((str[0] - '0') % 16 == 0);
 
    if(len == 2)
    	return (((str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 16 == 0);
 
 	if(len == 3)
		return (((str[len - 3] - '0') * 100 + (str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 16 == 0);
	
	return (((str[len - 4] - '0') * 1000 + (str[len - 3] - '0') * 100 + (str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 16 == 0); 
}
 
// Driver code
int main()
{
    char str[20];
	scanf("%s", str);
	if(isDivisibleBy16(str))
		printf("Divisible by 16");
	else
		printf("Not divisible");
	return 0;
}
