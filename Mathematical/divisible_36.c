#include<stdio.h>

int isDivisibleBy36(char* str)
{
	int len, i, sum = 0;
	for(len = 0; str[len]; len++);
	
	if(len == 0)
    	return 0;
 
    if(len == 1 && (str[0] - '0') % 4 != 0)
    	return 0;
 
	if(((str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 4 != 0)
		return 0;
	
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
	if(isDivisibleBy36(str))
		printf("Divisible by 36");
	else
		printf("Not divisible");
	return 0;
}
