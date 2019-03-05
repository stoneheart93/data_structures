#include<stdio.h>
#include<limits.h>
 
void bitonic(int a[], int n)
{
	int end_index = 0, max_len = INT_MIN;
	int i = 0;
	
	while(i + 1 < n)
	{
	    int len = 1;
	
		while(i + 1 < n && a[i] < a[i + 1])
		{
			i++;
			len++;
		}	
		
		while(i + 1 < n && a[i] > a[i + 1])
		{
			i++; 
			len++;
		}
		
		if (len > max_len)
        {
            max_len = len;
            end_index = i;
        }
	}

    printf("The length of longest bitonic sub-array is %d\n", max_len);
	printf("The longest bitonic sub-array is [%d, %d]", end_index - max_len + 1, end_index);
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	bitonic(a, n);
	return 0;
}

/*
ip
6
12 4 78 90 45 23
op
The length of longest bitonic sub-array is 5
The longest bitonic sub-array is [1, 5]
*/
