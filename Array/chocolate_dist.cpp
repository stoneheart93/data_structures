#include<iostream>
#include<algorithm>
using namespace std;

int findMinDiff(int a[], int n, int m)
{
	if(m == 0 || n == 0)
    	return 0;

	sort(a, a + n);

    if(n < m)
    	return -1;
 
    int min_diff = INT_MAX;
 
    for(int i = 0; i + m - 1 < n; i++)
    {
        int diff = a[i + m - 1] - a[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

int main() 
{
    int n, i, m;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	printf("%d", findMinDiff(a, n, m));
	return 0;
}
