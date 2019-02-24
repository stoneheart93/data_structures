#include<stdio.h>
 
int isDivisibleBy7(int n)
{
	if(n < 0)
		n = -n;
		
    if(n == 0 || n == 7)
        return 1;

    if(n < 10)
        return 0;

	// a - 2b ie, n/10 - 2*(n%10)
    return isDivisibleBy7( n / 10 - 2 * (n % 10) );
}

int main()
{
	int n;
	scanf("%d", &n);
	if(isDivisibleBy7(n))
		printf("Divisible by 7");
	else
		printf("Not divisible");
	return 0;
}
