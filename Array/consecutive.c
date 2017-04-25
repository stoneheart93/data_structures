#include<stdio.h>

int getMin(int a[], int n)
{
    int min = 999999, i;
    for(i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}
 
int getMax(int a[], int n)
{
    int max = 0, i;
    for(i = 1; i < n; i++)
    {
		if (a[i] > max)
            max = a[i];
	}
    return max;
}
 
int areConsecutive(int a[], int n)
{
	if(n < 1)
    	return 0;
 	
	int i, j;
	
	int min = getMin(a, n);
 	int max = getMax(a, n);
 
    if (max - min + 1 == n)
    {
        for(i = 0; i < n; i++)
        {
            if (a[i] < 0)
                j = -a[i] - min;
            else
                j = a[i] - min;
 
 		    if (a[j] > 0)
                a[j] = -a[j];
            else
                return 0;
        }
 
        return 1;
    }
	else
		return 0; 
}
 
int main()
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if(areConsecutive(a, n))
		printf("consecutive");
    else
        printf("not consecutive");
    return 0;
}

/*
ip
5
3 5 1 2 4
op
consecutive
*/
