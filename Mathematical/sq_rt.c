#include<stdio.h>

int sqroot(int input)
{
	int low = 0, high = 65535;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		int mid_sqr = mid * mid;
		if(input == mid_sqr)
			return mid;
		else if(input < mid_sqr)
			high = mid - 1;
	   	else
	    	low = mid + 1;
	}
	return -1;
}

int main()
{
	int input;
	scanf("%d", &input);
	printf("Square root: %d" , sqroot(input));
	return 0;
}
