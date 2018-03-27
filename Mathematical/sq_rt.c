#include<stdio.h>

int binary_search(int low, int high, int input)
{
	if(low <= high)
	{
		int mid = low + (high - low)/2;
		int mid_sqr = mid * mid;
		if(input == mid_sqr)
			return mid;
		else if(input < mid_sqr)
			return binary_search(low, mid - 1, input);
	   	else
	    	return binary_search(mid + 1, high, input);
	}
	return -1;
}

int sqroot(int n)
{
	binary_search(0, 65535, n);
}

int main()
{
	int input;
	scanf("%d", &input);
	printf("Square root: %d" , sqroot(input));
	return 0;
}
