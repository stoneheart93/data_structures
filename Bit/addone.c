#include<stdio.h>

int addOne(int n)
{
	return (-(~n));
}

int main()
{
	int num;
  	scanf("%d",&num);
  	printf("%d", addOne(num));
  	return 0;
}
