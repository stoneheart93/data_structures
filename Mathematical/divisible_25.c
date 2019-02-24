#include<stdio.h>

int isDivisibleBy25(char* str)
{
	int len = strlen(str);
	
	if(len == 0)
    	return 0;
    else if(len == 1 && str[0] == '0')
    	return 1;
    else
		return (((str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 25 == 0);
 
}

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
