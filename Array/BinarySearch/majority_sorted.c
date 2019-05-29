#include<stdio.h>

int first_occ(int a[], int low, int high, int key)
{
	int first = -1;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(key == a[mid])
		{
			first = mid;
			high = mid - 1;
		}
		else if(key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return first;
}

int isMajority(int a[], int n, int key)
{
	int first = first_occ(a, 0, n - 1, key);
	if(first == -1)
		return 0;
	
	if(first + n/2 < n && a[first] == a[first + n/2])
		return 1;
	else
		return 0; 
}

int main()
{
	int a[100];
    int n, i, key;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &key);
	if(isMajority(a, n, key))
		printf("Majority element");
	else
		printf("Not a majority element");
    return 0;
}
