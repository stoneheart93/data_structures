#include<stdio.h>
#define INIT_MAX 9999999

int min(int a, int b)
{
	return (a < b)?a : b;
}

int minJumps(int a[], int n)
{
    int jumps[n];  
    int i, j;
    if(n == 0 || a[0] == 0)
    	return INIT_MAX;
    jumps[0] = 0;

    for (i = 1; i < n; i++)
    {
        jumps[i] = INIT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + a[j] && jumps[j] != INIT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n-1];
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", minJumps(a, n));
	return 0;
}
