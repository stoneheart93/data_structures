#include<stdio.h>

int isDivisibleBy16(char* str)
{
	int len = strlen(str);
	
	if(len == 0)
		return 0;
	else if(len == 1)
    	return (str[0] == '0')
    else if(len == 2)
    	return (((str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 16 == 0);
 	else if(len == 3)
		return (((str[len - 3] - '0') * 100 + (str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 16 == 0);
	else
		return (((str[len - 4] - '0') * 1000 + (str[len - 3] - '0') * 100 + (str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 16 == 0); 
}
 
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
