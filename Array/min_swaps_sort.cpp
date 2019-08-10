#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int minSwaps(int a[], int n)
{
	int pos[n + 1];
	int visited[n] = {0};
	
	for(int i = 0; i < n; i++)
		pos[a[i]] = i + 1;

	for(int i = 0; i < n; i++)
		printf("%d %d ; ", a[i], pos[a[i]]);
	
	sort(pos, pos + n);
	int ans = 0;
	
	
	printf("\n");
	for(int i = 0; i < n; i++)
		printf("%d %d ; ", a[i], pos[a[i]]);
	
	for(int i = 0; i < n; i++)
	{
		if(visited[i] || pos[a[i]] == i + 1)
			continue;
			
		int j = i;
		int cycle = 0;
		while(!visited[j])
		{
			printf("%d ", j);
			visited[j] = 1;
			j = pos[a[j]] - 1;
			printf("%d\n", j);
			
			cycle++;			
		}
		
		if(cycle > 0)
			ans += cycle - 1;
	}
	return ans;
}

int main()
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", minSwaps(a, n));
    return 0;    
}
