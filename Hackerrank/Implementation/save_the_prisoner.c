#include<stdio.h>

int main()
{
	int t;
	int n, m, s;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d", &n, &m, &s);
		int d = s + m - 1;
		if(d % n == 0)
			printf("%d\n", n);
		else
			printf("%d", d % n);
	}
	return 0;
}
