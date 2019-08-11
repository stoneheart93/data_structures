#include<stdio.h>

int matches(int n)
{
	return n - 1;
}

int main()
{
	int players;
	scanf("%d", &players);
	printf("%d", matches(players));
	return 0;
}
