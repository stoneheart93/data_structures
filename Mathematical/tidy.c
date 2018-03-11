#include<stdio.h>

int isTidy(int n)
{
    int prev = 10;
    while(n)
    {
        int rem = n % 10;
        n /= 10;
        if(rem > prev)
        	return 0;
        prev = rem;
    }
    return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	if(isTidy(n))
		printf("Tidy");
	else
		printf("Not tidy");
	return 0;
}
