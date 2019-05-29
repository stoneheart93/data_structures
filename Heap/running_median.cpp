#include<queue>
#include<stdio.h>
using namespace std;

priority_queue <int> max_heap;
priority_queue <int, vector<int>, greater<int> > min_heap;

void add_numbers(int element)
{
	if(max_heap.size() == 0 || element < max_heap.top())
		max_heap.push(element);
	else
		min_heap.push(element);
}

void balance()
{
	int max_heap_size = max_heap.size();
	int min_heap_size = min_heap.size();
	
	if(max_heap_size - min_heap_size > 1)
	{
		min_heap.push(max_heap.top());
		max_heap.pop();
	}
	else if(min_heap_size - max_heap_size > 1)
	{
		max_heap.push(min_heap.top());
		min_heap.pop();
	}
}

float getMedian()
{
	if(max_heap.size() == min_heap.size())
		return ( max_heap.top() + min_heap.top() ) / 2.0;
	else if(max_heap.size() > min_heap.size())
		return max_heap.top();
	else if(min_heap.size() < max_heap.size())
		min_heap.top();
}

void running_median(int a[], int n)
{	
	for(int i = 0; i < n; i++)
	{
		add_numbers(a[i]);
		balance();
		printf("\n%f", getMedian());
	}
}

int main()
{
	int a[100];
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	running_median(a, n);
	return 0;
}
