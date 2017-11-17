#include<stdio.h>

int count_pattern(char* str)
{
	int count = 0, one_seen = 0;
	int i;
	for(i = 0; str[i]; i++)
	{
		if(str[i] == '1' && one_seen == 0)
			one_seen = 1;
		else if(str[i] != '1' && str[i] != '0')
			one_seen = 0;
		else if(str[i] == '1' && one_seen == 1)
		{
			if(str[i - 1] == '0')
				count++;
		}
	}
	return count;	
}

int main()
{
	char str[50];
	scanf("%s", str);
	printf("%d", count_pattern(str));
	return 0;
}
