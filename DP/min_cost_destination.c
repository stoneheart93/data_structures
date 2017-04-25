#include<stdio.h>
int N;
#define INF 9999999

int minCost(int cost[N][N])
{
	int dist[N];
	int i, j;
    for(i = 1; i <= N; i++)
        dist[i] = INF;
    dist[0] = 0;
    
	for(i = 0; i < N; i++)
	{
		for(j = i + 1; j < N; j++)
		{
		    if(dist[i] + cost[i][j] < dist[j])
        		dist[j] = dist[i] + cost[i][j];
       	}
    }
    
    return dist[N-1];
}
int main()
{
	int i, j;
	scanf("%d", &N);
	int cost[N][N];
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
	printf("%d", minCost(cost));
	return 0;
}

/*
ip
0 15 80 90
9999999 0 40 50
9999999 9999999 0 70
9999999 9999999 9999999 0
op
65
*/
