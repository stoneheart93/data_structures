#include<unordered_set>
using namespace std;

void fix(int a[], int n)
{
	unordered_set<int> hash;
	for(int i = 0; i < n; i++)
		hash.insert(a[i]);

	for(int i = 0; i < n; i++)
	{
		if(hash.find(i) != hash.end())
			a[i] = i;
		else
			a[i] = -1;
	}
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	fix(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
