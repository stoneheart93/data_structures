#include<stdio.h>

int findIndexUnsorted(int a[], int n, int key)
{
	int i, count = 0;
	int found = 0;
	for(i = 0; i < n; i++)
	{
		if(a[i] == key)
			found = 1;
		if(a[i] < key)
			count++;
	}	
	return found == 0 ? -1 : count;
}

int main() 
{
    int n, i, key;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &key);
	printf("%d", findIndexUnsorted(a, n, key));
 	return 0;
}
