#include<stdio.h>

int gcd(int a, int b)
{
	if(a == 0)
		return b;
	else if(b == 0)
		return a;
	else
		return gcd(b, a % b);	
}
int main()
{
	int t, l, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &l, &b);
		int g = gcd(l, b);
		printf("%d\n",((l / g) * (b / g));
	}
	return 0;
}
