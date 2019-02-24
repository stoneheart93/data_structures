#include<stdio.h>

int isDivisibleBy6(char* str)
{
	int len = strlen(str);
	int i, sum = 0;
	
	if((str[len - 1] - '0') % 2 != 0)
       return 0;
	
	for(i = 0; i < len; i++)
	{
		sum += (str[i] - '0');	
	}
	return (sum % 3 == 0);
}
 
int main()
{
    char str[20];
	scanf("%s", str);
	if(isDivisibleBy6(str))
		printf("Divisible by 6");
	else
		printf("Not divisible");
	return 0;
}
