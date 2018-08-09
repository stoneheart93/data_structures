#include<stdio.h>
 
int isDuck(char* num)
{
	int i;
	for(i = 1; num[i]; i++)
	{
		if(num[i] == '0')
			return 1;
	}
	return 0;
}
 
int main()
{
    char num[10];
    scanf("%s", num);
	if(isDuck(num) && num[0] != 0)
		printf("Duck Number");
	else
		printf("Not a duck Number");
    return 0;
}
