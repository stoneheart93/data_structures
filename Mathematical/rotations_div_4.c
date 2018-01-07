#include<stdio.h>

int countRotationsby4(char* str)
{
	int len, count = 0;
	for(len = 0; str[len]; len++);
	
	if(len == 1)
	{
		int digit = str[0] = '0';
		if(digit % 4 == 0)
			return 1;
		else
			return 0;
	}
	else 
	{
		int i;
		for(i = 0; i < len - 1; i++)
		{
			int two_digit_pair = (str[i] - '0') * 10 + (str[i + 1] - '0') ;
			if(two_digit_pair % 4 == 0)
				count++;
		}
		
		int last_1_first_1 = (str[len - 1] - '0') * 10 + (str[0] - '0');
		if(last_1_first_1 % 4 == 0)
			count++;
		
		return count;		
	}
		
}


int main()
{
	char str[20];
	scanf("%s", str);
	printf("%d", countRotationsby4(str));
	return 0;
}
