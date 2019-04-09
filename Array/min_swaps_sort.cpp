#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int minSwaps(int a[], int n)
{
	pair<int, int> apos[n];
	int visited[n] = {0};
	
	for(int i = 0; i < n; i++)
	{
		apos[i].first = a[i];
		apos[i].second = i;
	}
	
	sort(apos, apos + n);
	int ans = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(visited[i] || apos[i].second == i)
			continue;
			
		int j = i;
		int cycle = 0;
		while(!visited[j])
		{
			visited[j] = 1;
			j = apos[j].second;
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
