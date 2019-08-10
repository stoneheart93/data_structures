#include<stdio.h>

int findDuplicate(int a[], int n)
{
	int slow = n;
    int fast = n;
    
    do
    {
        slow = a[slow - 1];
        fast = a[a[fast - 1] - 1];
    }while(slow != fast);
    
    slow = n;
    
    do
    {
        slow = a[slow - 1];
        fast = a[fast - 1];
    }while(slow != fast);
    
    return slow;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", findDuplicate(a, n));
	return 0;
}

