#include<stdio.h>

int max(int a, int b)
{
	return (a > b)? a: b;
}
int maxConsOne(int a[], int n)
{
    int i, count = 0, result = 0; 
 
    for(i = 0; i < n; i++)
    {
        if(a[i] == 0)
            count = 0;
        else
        {
            count++;
            result = max(result, count);
        }
    }
    return result;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", maxConsOne(a, n));
	return 0;
}


