#include<stdio.h>

int pow(int x, int y)
{
	int result = 1;
	while(y > 0)
	{
		if(y & 1)
			result *= x;
		y = y >> 1;
		x = x * x;
	}
	return result;
}

int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d", pow(x, y));
	return 0;
}
