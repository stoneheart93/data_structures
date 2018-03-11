#include<stdio.h>

int isLucky(int pos)
{
	int counter = 2;
	while(pos >= counter)
	{
		if(pos % counter == 0)
			return 0;
		pos -= pos/counter;
		counter++;
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	if(isLucky(n))
		printf("Lucky");
	else
		printf("Not lucky");
	return 0;
}
