#include<stdio.h>

void count(int a[], int n)
{
	int i;
	int neg = 0, pos = 0, zero = 0;
    for(i = 0; i < n; i++)
	{
        if(a[i] < 0)
            neg++;
        else if(a[i] > 0)
            pos++;
        else 
            zero++;
    }
    float pos_fra = (float)pos / n;
    float neg_fra = (float)neg / n;
    float zero_fra = (float)zero / n;
    printf("%f\n%f\n%f", pos_fra, neg_fra, zero_fra);   
}


int main()
{
	int n, i; 
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
	{
       scanf("%d", &a[i]);
    }
    count(a, n);
    return 0;
}

