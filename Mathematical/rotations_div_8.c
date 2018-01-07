#include<stdio.h>

int countRotationsby8(char* str)
{
	int len, count = 0;
	for(len = 0; str[len]; len++);
	
	if(len == 1)
	{
		int digit = str[0] = '0';
		if(digit % 8 == 0)
			return 1;
		else
			return 0;
	}
	else if(len == 2)
	{
		int first_pair = (str[0] - '0') * 10 + (str[1] - '0');
		int second_pair = (str[1] - '0') * 10 + (str[0] - '0');
		if(first_pair % 8 == 0)
			count++;
		if(second_pair % 8 == 0)
			count++;
		return count;
	}
	else
	{
		int i;
		for(i = 0; i < len - 2; i++)
		{
			int three_digit_pair = (str[i] - '0') * 100 + (str[i + 1] - '0') * 10 + (str[i + 2] - '0');
			if(three_digit_pair % 8 == 0)
				count++;
		}
		
		int last_2_first_1 = (str[len - 2] - '0') * 100 + (str[len - 1] - '0') * 10 + (str[0] - '0');
		if(last_2_first_1 % 8 == 0)
			count++;
		
		int last_1_first_2 = (str[len - 1] - '0') * 100 + (str[0] - '0') * 10 + (str[1] - '0');
		if(last_1_first_2 % 8 == 0)
			count++;
		
		return count;		
	}
		
}


int main()
{
	char str[20];
	scanf("%s", str);
	printf("%d", countRotationsby8(str));
	return 0;
}
