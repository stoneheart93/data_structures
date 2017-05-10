#include<stdio.h>

int prevPowerOf2(int n)
{
    if(n < 1)
    	return 0;
	int res = 0, i;
 
	for(i = 0; i < 8*sizeof(int); i++)
    {
        int curr = 1 << i;
		if(curr > n)
        	break;
		res = curr;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", prevPowerOf2(n));
    return 0;
}
