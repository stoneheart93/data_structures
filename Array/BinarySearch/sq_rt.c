#include<stdio.h>

int sqroot(int input)
{
	int low = 0, high = input/2; // Floor of square root of input cannot be more than input/2 when input > 1
	int ans = -1;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		int mid_sqr = mid * mid;
		if(mid_sqr == input)
			return mid;
		else if(mid_sqr < input)
		{
			ans = mid;
			low = mid + 1;
	   	}
		else
	    	high = mid - 1;
	}
	return ans;
}

int main()
{
	int input;
	scanf("%d", &input);
	printf("Square root: %d" , sqroot(input));
	return 0;
}
