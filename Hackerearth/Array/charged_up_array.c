// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/charged-up-array-f35a5e23/description/

#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<math.h>
#define M 1000000007

int solve (long long* a, int n) 
{
    if(n >= 64)
        return 0;
    long long int k = pow(2, n - 1);
    long long int result = 0;
   
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= k)
            result = (result % M + a[i] % M) % M;  
    }
    return result;
}

int main() 
{
    int tc, i, n;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        long long int *a = (long long int*)malloc(sizeof(long long int) * n);
        for(int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        printf("%d\n", solve(a, n));
        free(a);
    }        
    return 0;
}
