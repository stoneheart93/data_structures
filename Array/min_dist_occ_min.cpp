#include<iostream>
#include<vector>
using namespace std;
#define INIT_MAX 9999

int findClosestMin(int a[], int n)
{
	int min = INIT_MAX;
	
    for(int i = 0; i < n; i++)
    {
		if(a[i] < min)
        	min = a[i];
	}
    
	vector<int> indexes;
	for(int i = 0; i < n; i++)
    {
		if(a[i] == min)
        	indexes.push_back(i);
	}
    
	if(indexes.size() < 2)
    	return -1;
 
    int min_dist = INIT_MAX;
 
    for(int i = 1; i < indexes.size(); i++)
	{ 
        if((indexes[i] - indexes[i - 1]) < min_dist)
            min_dist = (indexes[i] - indexes[i - 1]);
	}
    return min_dist;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", findClosestMin(a, n));
	return 0;
}

