#include<stdio.h>

int countWays(int N)
{
    if (N == 1)
        return 4;  
 
    int countB = 1, countS = 1;
	int prev_countB, prev_countS;
	int i;
	
    for(i = 2; i <= N; i++)
    {
        prev_countB = countB;
        prev_countS = countS;
 
        countS = prev_countB + prev_countS;
        countB = prev_countS;
    }

    int result = countS + countB;
    return (result*result);
}
 
int main()
{
    int N;
    scanf("%d", &N);
    printf("%d", countWays(N));
    return 0;
}
