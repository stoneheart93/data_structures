#include<stdio.h>

void printLeaders(int a[], int n)
{
    int max_from_right = a[n - 1];
    int i;
    printf("%d ", max_from_right);
    for(i = n - 2; i >= 0; i--)
    {
        if(max_from_right < a[i])
        {
            printf("%d ", a[i]);
        	max_from_right = a[i];
        }
    }    
}

int main()
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printLeaders(a, n);
    return 0;    
}    

/*
ip
6
16 17 4 3 5 2
op
2 5 17
*/
