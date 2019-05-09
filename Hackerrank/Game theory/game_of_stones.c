#include<stdio.h>

int main()
{
	int n, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		if(n % 7 == 0 || n % 7 == 1)
			printf("Second\n");
		else
			printf("First\n");
	}
	return 0;
}
