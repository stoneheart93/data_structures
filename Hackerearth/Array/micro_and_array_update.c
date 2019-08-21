//hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/micro-and-array-update/

#include<stdio.h>
#include<limits.h>

int minTime(int a[], int N, int K)
{
	int min = INT_MAX;
	int i;
	for(i = 0; i < N; i++)
	{
		if(a[i] < min)
			min = a[i];
	}
	return ((K > min)? K - min: 0);
}

int main()
{
    int t, i, N, K;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &N, &K);
        int* a = (int*)malloc(sizeof(int) * N);
    	for(i = 0; i < N; i++)
            scanf("%d", &a[i]);
        printf("%d\n", minTime(a, N, K));
    
	    free(a);
    }
    return 0;
}
