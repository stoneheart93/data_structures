#include<unordered_set>
using namespace std;

int subarraySum0(int a[], int n)
{
	int i, sum = 0;
	unordered_set<int> hash;
	for(i = 0; i < n; i++)
	{
		sum += a[i];
		if(sum == 0 || hash.find(sum) != hash.end())
			return 1;
		else
			hash.insert(sum);
	}
	return 0;
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if(subarraySum0(a, n))
		printf("Subarray with sum 0 exists");
	else
		printf("Subarray doesnt exist");
	return 0;
}
