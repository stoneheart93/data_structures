#include<unordered_map>
using namespace std;

int max(int a, int b)
{
	return ((a > b)? a : b);
}

int countSubarray01(int a[], int n)
{
	int i, count = 0, maxlen = 0, sum = 0;
	unordered_map<int, int> m;
	for(i = 0; i < n; i++)
	{
		sum += (a[i] == 0) ? -1 : 1;
		if(sum == 0)
            count++;
		if(m.find(sum) != m.end())
			count++;
		else
			m[sum] = i;
	}
	for (auto itr = m.begin(); itr != m.end(); itr++) {
 		printf("%d %d\n", itr->first, itr->second);
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
