#include<iostream>
using namespace std;
int E1[1000], E2[1000], W[1000];
int parent[1000], rank[1000];
int N, E;

int swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition (int W[], int E1[], int E2[], int low, int high)
{
    int pivot = W[high];    
    int i = (low - 1);  
 
    for(int j = low; j <= high- 1; j++)
    {
        if(W[j] <= pivot)
        {
            i++;    
            swap(&W[i], &W[j]);
            swap(&E1[i], &E1[j]);
            swap(&E2[i], &E2[j]);
        }
    }
    swap(&W[i + 1], &W[high]);
    swap(&E1[i + 1], &E1[high]);
    swap(&E2[i +1], &E2[high]);
    return (i + 1);
}
 
void quickSort(int arr[], int E1[], int E2[], int low, int high)
{
    if(low < high)
    {
 	   int p = partition(arr, E1, E2, low, high);
       quickSort(arr, E1, E2, low, p - 1);
       quickSort(arr, E1, E2, p + 1, high);
    }
}

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

void kruskal()
{
	int e = 1, j = 1;
	quickSort(W, E1, E2, 1, E);
    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    while(e <= N - 1 && j <= E)
    {
        int x = find(E1[j]);
        int y = find(E2[j]);
        if(x != y)
        {
        	cout << E1[j] << " " << E2[j] << " " << W[j] << endl;
        	Union(x, y);
        	e++;
        }
        j++;
    }
}

int main()
{
    scanf("%d%d", &N, &E);
    for(int i = 1; i <= E; i++)
    	scanf("%d%d%d", &E1[i], &E2[i], &W[i]);
    kruskal();
    return 0;
}

/*
ip
4 5
1 2 10
1 3 6
1 4 5
2 4 15
3 4 4
op
3 4 4
1 4 5
1 2 10
*/
