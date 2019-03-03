/*
Elements to be added so that all elements of a range are present in array
*/

#include<iostream>
#include<unordered_set>
using namespace std;
 
int countNum(int a[], int n)
{
    unordered_set<int> hash;
    int count = 0, max = INT_MIN, min = INT_MAX;

    for(int i = 0; i < n; i++) 
	{
        hash.insert(a[i]);
        
		if(a[i] < min)
        	min = a[i];
        if(a[i] > max)
        	max = a[i];
    }
    
    for(int i = min; i <= max; i++)
    {
        if(hash.find(i) == hash.end())
        	count++;
    }
	return count;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d ", countNum(a, n));
 	return 0;
}

