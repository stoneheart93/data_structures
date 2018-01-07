#include<stdio.h>

int isDivisibleBy9(char* str)
{
	int len, i, sum = 0;
	for(len = 0; str[len]; len++);
	
	for(i = 0; i < len; i++)
	{
		sum += (str[i] - '0');	
	}
	return (sum % 9 == 0);
}
 
// Driver code
int main()
{
    char str[20];
	scanf("%s", str);
	if(isDivisibleBy9(str))
		printf("Divisible by 9");
	else
		printf("Not divisible");
	return 0;
}
