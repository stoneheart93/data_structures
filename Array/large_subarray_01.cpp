#include<unordered_map>
using namespace std;

int max(int a, int b)
{
	return ((a > b)? a : b);
}

int subarray01(int a[], int n)
{
	int sum = 0, maxlen = 0;
	unordered_map<int, int> hash;
	
	for(int i = 0; i < n; i++)
	{
		sum += (a[i] == 0) ? -1 : 1;
		if(sum == 0)
            maxlen = i + 1;
            
		if(hash.find(sum) != hash.end())
			maxlen = max(maxlen, i - hash[sum]);
		else
			hash[sum] = i;
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
