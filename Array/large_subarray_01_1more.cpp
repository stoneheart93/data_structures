#include<unordered_map>
using namespace std;

int max(int a, int b)
{
	return ((a > b)? a : b);
}

int subarray01_1more(int a[], int n)
{
	int i, count = 0, maxlen = 0;
	unordered_map<int, int> m;
	for(i = 0; i < n; i++)
	{
		count += (a[i] == 0) ? -1 : 1;
		if(count == 1)
            maxlen = i + 1;
		if(m.find(count - 1) != m.end())
			maxlen = max(maxlen, i - m[count - 1]);
		else if(m.find(count) == m.end())
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
	printf("%d", subarray01_1more(a, n));
	return 0;
}
