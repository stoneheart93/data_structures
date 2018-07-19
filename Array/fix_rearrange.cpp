#include<unordered_set>
using namespace std;

void fix(int a[], int n)
{
	int i;
	unordered_set<int> s;
	for(i = 0; i < n; i++)
	{
		s.insert(a[i]);
	}
	for(i = 0; i < n; i++)
	{
		if(s.find(i) != s.end())
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
