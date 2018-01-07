#include<stdio.h>

void get2NonRepeating(int a[], int n, int* x, int* y)
{
	int i, Xor = 0, set_bit_no;  
  	*x = 0;
  	*y = 0;
  	
	for(i = 0; i < n; i++)
    	Xor ^= a[i];  
  	
  	set_bit_no = Xor & -Xor;
 
 	for(i = 0; i < n; i++)
  	{
    	if(a[i] & set_bit_no)
      		*x ^= a[i]; 
    	else
      		*y ^= a[i]; 
  	}
}     
 
int main()
{
	int n, i, x, y;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	get2NonRepeating(a, n, &x, &y);
	printf("Two Non Repeating elements: %d %d", x, y); // odd occurrences of two elements in an array 
	return 0;
}

/*
ip
8
2 3 7 9 11 2 3 11
op
Two Non Repeating elements: 7 9
*/
