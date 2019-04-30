#include<stdio.h>

void print_date(int year)
{
	if(year >= 1919) //gregorian
	{
		if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			printf("12.09.%d",year);
		else
			printf("13.09.%d",year);
	}
	else if(year >= 1700 && year <= 1917) //julian
	{
		if(year % 4 == 0)
			printf("12.09.%d",year);
		else
			printf("13.09.%d",year);
	}
	else if(year == 1918)
		printf("26.09.%d", year);
}

int main()
{
	int year;
	scanf("%d", &year);
	print_date(year);
	return 0;
}
