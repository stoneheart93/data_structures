#include<stdio.h>
#include<algorithm>
using namespace std;

struct Interval
{
	int start, end;
};

int max(int a, int b)
{
	return (a > b) ? a : b;
}

bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

void mergeIntervals(Interval a[], int n)
{
	sort(a, a + n, compareInterval);
	Interval prev = a[0];
	for(int i = 1; i < n; i++)
	{
		if(a[i].start > prev.end)
		{
			printf("(%d, %d)", prev.start, prev.end);
			prev = a[i];
		}
		else
		{
			prev.end = max(prev.end, a[i].end);
			if(i == n - 1)
				printf("(%d, %d)", prev.start, prev.end);
		}
	}
	
}
int main()
{
	int n = 4;
    Interval a[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    mergeIntervals(a, n);
    return 0;
}

