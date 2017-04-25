#include<stdio.h>

int min(int a, int b, int c)
{
    if(a <= b)
    {
    	if(a <= c)
        	return a;
      	else
        	return c;
    }
    if(b <= c)
    	return b;
    else
    	return c;
}

int ugly(int n)
{
    int ugly[n];
	int i, i2 = 0, i3 = 0, i5 = 0;
    int next_mul_2 = 2, next_mul_3 = 3, next_mul_5 = 5;
    int next_ugly_no = 1;
    ugly[0] = 1;
    
    for(i = 1; i < n; i++)
    {
       next_ugly_no = min(next_mul_2, next_mul_3, next_mul_5);
       ugly[i] = next_ugly_no;                    
       if(next_ugly_no == next_mul_2)
       {
           i2++;       
           next_mul_2 = ugly[i2] * 2;
       }
       if(next_ugly_no == next_mul_3)
       {
           i3 = i3 + 1;
           next_mul_3 = ugly[i3] * 3;
       }
       if(next_ugly_no == next_mul_5)
       {
           i5 = i5 + 1;
           next_mul_5 = ugly[i5] * 5;
       }
    } 
    return next_ugly_no;
}
 
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", ugly(n));
    return 0;
}

/*
ip:
150
op:
5832
*/
