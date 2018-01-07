#include<stdio.h>

int isDivisibleBy11(char* str)
{
	int len, i, oddsum = 0, evensum = 0;
	for(len = 0; str[len]; len++);
	
	for(i = 0; i < len; i++)
	{
		if(i % 2 == 0)
			oddsum += (str[i] - '0');
		else
			evensum += (str[i] - '0');	
	}
	return ((oddsum - evensum) % 11 == 0);
}
 
// Driver code
int main()
{
    char str[20];
	scanf("%s", str);
	if(isDivisibleBy11(str))
		printf("Divisible by 11");
	else
		printf("Not divisible");
	return 0;
}
