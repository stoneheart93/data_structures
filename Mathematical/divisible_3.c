#include<stdio.h>

int isDivisibleBy3(char* str)
{
	int len, i, sum = 0;
	for(len = 0; str[len]; len++);
	
	for(i = 0; i < len; i++)
	{
		sum += (str[i] - '0');	
	}
	return (sum % 3 == 0);
}
 
// Driver code
int main()
{
    char str[20];
	scanf("%s", str);
	if(isDivisibleBy3(str))
		printf("Divisible by 3");
	else
		printf("Not divisible");
	return 0;
}
