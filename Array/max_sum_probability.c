#include<stdio.h>

int countMaxSumPairs(int a[], int n)
{
	int i;
    int first = 0, second = 0;
    for(i = 0; i < n; i++) 
	{
        if(a[i] > first) 
		{
        	second = first;
        	first = a[i];
        }
        else if(a[i] > second && a[i] != first)
            second = a[i];
    }
 
    int cnt1 = 0, cnt2 = 0;
    for(i = 0; i < n; i++) 
	{
        if(a[i] == first)
            cnt1++;
        if(a[i] == second)
            cnt2++;
    }
    if(cnt1 == 1) 
    	return cnt2;
     
    if(cnt1 > 1) 
        return cnt1 * (cnt1 - 1) / 2;    
}
 
float findMaxSumProbability(int a[], int n)
{
    int total = n * (n - 1) / 2;
    int max_sum_pairs = countMaxSumPairs(a, n);
    return (float)max_sum_pairs / (float)total;
}
 
int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%f", findMaxSumProbability(a, n));
 	return 0;
}


/*
ip
4
1 2 2 3
op
0.333333
*/
