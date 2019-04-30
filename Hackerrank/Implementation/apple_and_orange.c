#include<stdio.h>

int main()
{
	int s, t, a, b, m, n, apple_dist, orange_dist;
	int apple_count = 0, orange_count = 0;
	scanf("%d%d", &s, &t);
	scanf("%d%d", &a, &b);
	scanf("%d%d", &m, &n);
	while(m--)
	{
		scanf("%d", &apple_dist);
		if(a + apple_dist >= s && a + apple_dist <= t)
			apple_count++;
	}
	while(n--)
	{
		scanf("%d", &orange_dist);
		if(b + orange_dist >= s && b + orange_dist <= t)
			orange_count++;
	}
	printf("%d\n%d", apple_count, orange_count);
	return 0;
}
