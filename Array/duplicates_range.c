#include<stdio.h>
 
void printDuplicates(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++)
    {
        int index = a[i] % n;
        a[index] += n;
    }
 
 	for(i = 0; i < n; i++)
    {
        if ((a[i] / n) > 1)
            printf("%d ", i);
    }
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printDuplicates(a, n);
	return 0;
}

/*
ip
7
1 2 3 1 3 6 6 
op
The repeating elements are:
1 3 6
*/
