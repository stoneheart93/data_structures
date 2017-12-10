#include<stdio.h>

int linear_search(int a[], int n, int key)
{
    int i;
    for(i = 0; i < n; i++)
    {
    	if(a[i] == key)
        	return i;
	}    
    return -1;
}

int main() 
{
    int n, i, key;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &key);
	printf("Position: %d", linear_search(a, n, key));
	return 0;
}

