#include<stdio.h>

/*
For eg: a[] = [1, 2, 3], n = 3
All subarrays :  [1], [1, 2], [1, 2, 3], [2], [2, 3], [3]
first element 'a[0]' appears 3 times    
second element 'a[1]' appears 4 times  
third element 'a[2]' appears 3 times

Every element a[i] appears in two types of subsets:
i)  In subarrays beginning with a[i]. There are 
    (n-i) such subsets. For example [2] appears
    in [2] and [2, 3].
ii) In subarrays where this element is not first element. 
	There are (n-i)*i subsets. For example [2] appears in 
    [1, 2] and [1, 2, 3].

Total of above (i) and (ii) = (n-i) + (n-i)*i 
                            = (n-i)(i+1)
*/

int allSubarraySum(int a[], int n)
{
	int i, sum = 0;
	for(i = 0; i < n; i++)
		sum += (a[i] * (n - i) * (i + 1)); 
	return sum;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", allSubarraySum(a, n));
	return 0;
}
