#include<unordered_map>
using namespace std;

int max(int a, int b)
{
	return ((a > b)? a : b);
}

int subarray0(int a[], int n)
{
	int i, sum = 0, maxlen = 0;
	unordered_map<int, int> m;
	for(i = 0; i < n; i++)
	{
		sum += a[i];
		if(m.find(sum) != m.end())
			maxlen = max(maxlen, i - m[sum]);
		else
			m[sum] = i;
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
	printf("%d", subarray0(a, n));
	return 0;
}
