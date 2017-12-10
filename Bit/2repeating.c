#include<stdio.h>

void get2repeating(int a[], int n, int* x, int* y)
{
	int i, Xor = 0, set_bit_no;  
  	*x = 0;
  	*y = 0;
  	
	for(i = 0; i < n; i++)
    	Xor ^= a[i];  
  	for(i = 1; i <= n - 2; i++)
    	Xor ^= i;   
 
  	set_bit_no = Xor & -Xor;
 
 	for(i = 0; i < n; i++)
  	{
    	if(a[i] & set_bit_no)
      		*x ^= a[i]; 
    	else
      		*y ^= a[i]; 
  	}
  	for(i = 1; i <= n - 2; i++)
  	{
    	if(i & set_bit_no)
      		*x ^= i; 
    	else
     	 	*y ^= i; 
  	}
}     
 
int main()
{
	int n, i, x, y;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	get2repeating(a, n, &x, &y);
	printf("Two repeating elements: %d %d", x, y);
	return 0;
}

/*
ip
7
4 2 4 5 2 3 1
op
Two repeating elements: 2 4
*/
