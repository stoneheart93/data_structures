#include<stdio.h>

int min(int a, int b)
{
	return (a < b)? a : b;
}

int countNums(int n, int x, int y)
{
    static int a[100];
 	
	if(x <= n)
    	a[x] = 1;
    if(y <= n)
        a[y] = 1;
 
    int i, result = 0;
 
    for(i = min(x, y); i <= n; i++)
    {
        if(a[i])
        { 
            if(i + x <= n)
                a[i + x] = 1;
            if(i + y <= n)
                a[i + y] = 1;
            result++;
        }
    }
    return result;
}

int main()
{
	int n, x, y;
	scanf("%d", &n);
	scanf("%d %d", &x, &y);
	printf("%d", countNums(n, x, y));
	return 0;
}


