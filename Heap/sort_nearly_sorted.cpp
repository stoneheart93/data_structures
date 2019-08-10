#include<queue>
#include<stdio.h>
using namespace std;

void sort_nearly_sorted(int a[], int n, int k)
{
	priority_queue <int, vector<int>, greater<int> > min_heap;
	
	for(int i = 0; i < k + 1; i++)
		min_heap.push(a[i]);
		
	int index = 0;
	for(int i = k + 1; i < n; i++)
	{
		a[index++] = min_heap.top();
		min_heap.pop();
		
		min_heap.push(a[i]);
	}
	
	while(!min_heap.empty())
	{
		a[index++] = min_heap.top();
		min_heap.pop();
	}
}

int main()
{
	int n, i, k;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	sort_nearly_sorted(a, n, k);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
 	return 0;
}

