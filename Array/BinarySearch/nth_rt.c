#include<stdio.h>

double nroot(double input, int n)
{
	double low, high; // Floor of square root of input cannot be more than input/2 when input > 1
	
	if(input >= 0 && input <= 1)
	{
		low = input;
		high = 1;
	}
	else
	{
		low = 1; 
		high = input;
	}
	
	double epsilon = 0.00000001; 
	double mid = low + (high - low)/2;
	double error = abs((pow(mid, n)) - input);

	while(error >= epsilon)
	{
		if(pow(mid, n) > input)
			high = mid - 1;
		else
	    	low = mid + 1;
	    	
	    mid = low + (high - low)/2;
		error = abs((pow(mid, n)) - input);
	}
	return mid;
}

int main()
{
	int input, n;
	scanf("%d%d", &input, &n);
	printf("Square root: %f" , nroot(input, n));
	return 0;
}
