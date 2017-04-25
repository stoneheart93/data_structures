#include<stdio.h>
#include<stdlib.h>
 
void printDuplicates(int a[], int n)
{
	int i;
  	printf("The repeating elements are: \n");
  	for(i = 0; i < n; i++)
  	{
    	if(a[abs(a[i])] >= 0)
      		a[abs(a[i])] = - a[abs(a[i])];
    	else
      		printf("%d ", abs(a[i]));
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
