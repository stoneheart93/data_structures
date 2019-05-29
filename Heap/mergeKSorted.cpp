#include<queue>
#include<utility>
#include<stdio.h>
using namespace std;

typedef pair<int, pair<int, int> > ppi;

void mergeKsorted(vector<vector<int> > a, int k)
{
	vector<int> result;
	
	priority_queue<ppi, vector<ppi>, greater<ppi> > min_heap;
	
	for(int i = 0; i < k; i++)
		min_heap.push( { a[i][0], {i, 0} } );

	while(!min_heap.empty())
	{
		ppi temp = min_heap.top();
		min_heap.pop();
		
		int element = temp.first;
		int array_no = temp.second.first;
		int index = temp.second.second;
		
		result.push_back(element);
		if(index + 1 < a[array_no].size())
			min_heap.push( { a[array_no][index + 1], {array_no, index + 1} } );
	}
	
	for(int i = 0; i < result.size(); i++)
		printf("%d ", result[i]);
}

int main()
{
	vector<vector<int> > a{ { 2, 6, 12 }, 
                            { 1, 9 }, 
                            { 23, 34, 90, 2000 } }; 
    int k = 3;
    mergeKsorted(a, k);
    return 0;                              
}
