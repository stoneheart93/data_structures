#include<stdio.h>
#include<string.h>
 
int min(int a, int b, int c)
{
    if(a <= b)
    {
    	if(a <= c)
        	return a;
      	else
        	return c;
    }
    if(b <= c)
    	return b;
    else
    	return c;
}
 
int editDistance(char* str1, char* str2, int m, int n)
{
	int dp[m + 1][n + 1];
	int i, j;
    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0)
                dp[i][j] = j;  
			else if(j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 			else
                dp[i][j] = 1 + min(dp[i][j - 1],  // Insert
                                   dp[i - 1][j],  // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }
    return dp[m][n];
}

int main()
{
    char str1[20];
    char str2[20];
    scanf("%s %s", str1, str2);
    printf("%d", editDistance(str1, str2, strlen(str1), strlen(str2)));
    return 0;
}

/*
ip:
saturday
sunday
op:
3
*/
