#include<stdio.h>

int main()
{
	int n, i;
	scanf("%d", &n);
	int like, share = 5, like_count = 0;
	for(i = 0; i < n; i++)
	{
		like = share/2;
		like_count += like;
		share = like*3;
	}
	printf("%d", like_count);
	return 0;
}
