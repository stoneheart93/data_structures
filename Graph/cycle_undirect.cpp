#include<iostream>
using namespace std;
int E1[1000], E2[1000];
int parent[1000], rank[1000];
int N, E;

int find(int x)
{
    if(x != parent[x])
        find(parent[x]);
    return parent[x];   
}
void Union(int x, int y)
{
    int x1 = find(x);
    int y1 = find(y);
     
    if(rank[x1] > rank[y1])
        parent[y1] = x1;
    else if(rank[y1] > rank[x1])
        parent[x1] = y1;
    else
    {
    	parent[x1] = y1;
        rank[y1]++;
 	}
}

int isCycle()
{
    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    for(int i = 1; i <= E; i++)
    {
        int x = find(E1[i]);
        int y = find(E2[i]);
        if(x == y)
            return 1;
        Union(x, y);
    }
    return 0;
}

int main()
{
    scanf("%d%d", &N, &E);
    for(int i = 1; i <= E; i++)
    	scanf("%d%d", &E1[i], &E2[i]);
    if(isCycle())
    	cout << "There is a cycle";
    else
    	cout << "No cycle";
    return 0;
}

/*
ip
3 3
1 2
2 3
3 1
op
There is a cycle
*/
