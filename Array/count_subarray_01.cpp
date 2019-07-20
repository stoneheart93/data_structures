#include<unordered_map>
using namespace std;

int max(int a, int b)
{
	return ((a > b)? a : b);
}

int countSubarray01(int a[], int n)
{
	int count = 0, sum = 0;
	unordered_map<int, int> hash;
	
	for(int i = 0; i < n; i++)
	{
		sum += (a[i] == 0) ? -1 : 1;
		hash[sum]++;
	}
	
	if(hash.find(0) != hash.end())
		count += hash[0];
	
	for(auto it = hash.begin(); it != hash.end(); it++) 
	{
		if(it->second > 1)
			count += (it->second * (it->second - 1)) / 2;
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
	printf("%d", countSubarray01(a, n));
	return 0;
}
