#include<map>
using namespace std;

int max(int a, int b)
{
	return ((a > b)? a : b);
}

int subarray01(int a[], int n)
{
	int i, count = 0, maxlen = 0;
	map<int, int> m;
	for(i = 0; i < n; i++)
	{
		count += (a[i] == 0) ? -1 : 1;
		if(m.find(count) != m.end())
			maxlen = max(maxlen, i - m[count]);
		else
			m[count] = i;
	}
	return maxlen;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", subarray01(a, n));
	return 0;
}
