#include<unordered_set>
using namespace std;

int subset(int a1[], int m, int a2[], int n)
{
	unordered_set<int> s;
	for(int i = 0; i < m; i++)
	{
		s.insert(a1[i]);
	}
	for(int i = 0; i < n; i++)
	{
		if(s.find(a2[i]) == s.end())
			return 0;
	}
	return 1;
}

int main()
{
	int m, n, i;
	int a1[20], a2[20];
	scanf("%d", &m);
	for(i = 0; i < m; i++)
		scanf("%d", &a1[i]);
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a2[i]);
	if(subset(a1, m, a2, n))
		printf("A2 is subset of A1");
	else
		printf("Not a subset");
	return 0;
}

