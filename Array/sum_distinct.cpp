#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findSum(int a[], int n)
{
    int sum = 0;
    unordered_set<int> s;
    for(int i = 0; i < n; i++)
    {
        if(s.find(a[i]) == s.end())
        {
            sum += a[i];
            s.insert(a[i]);
        }
    }
    return sum;
}
 
int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d ", findSum(a, n));
	return 0;
}
 
 
