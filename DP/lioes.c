#include<stdio.h>

int Lioes(int a[], int n)
{
    int lioes[n];
    int i, j, max = 0;
    for(i = 0; i < n; i++)
        lioes[i] = 1;
    for(i = 1; i < n; i++)
    {
    	for(j = 0; j < i; j++)
        {
            if(a[i] > a[j] && (a[i] + a[j]) % 2 != 0 && lioes[i] < lioes[j] + 1)
                lioes[i] = lioes[j] + 1;
        }
    }
    for(i = 0; i < n; i++)
    {
    	if(lioes[i] > max)
        	max = lioes[i];
    }
    return max;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    printf("%d", Lioes(a,n));
    return 0;
}

