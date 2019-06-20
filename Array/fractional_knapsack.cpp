#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	double costperweight_a = a.second / a.first;
	double costperweight_b = b.second / b.first;
	return costperweight_a > costperweight_b;
}

double fractionalKnapsack(int wt[], int val[], int n, int W)
{
	pair<int, int> s[n];
	for(int i = 0; i < n; i++)
		s[i] = make_pair(wt[i], val[i]);
		
	sort(s, s+n, compare);
	
	double profit = 0;
	int currentWeight = 0;
	for(int i = 0; i < n; i++)
	{
		if(currentWeight + s[i].first <= W)
		{
			currentWeight += s[i].first;
			profit += s[i].second;
		}
		else
		{
			int remWeight = W - currentWeight;
			profit += ((double)s[i].second / (double)s[i].first) * (double)remWeight;
		}
	}
	
	return profit;
}

int main()
{
	int n, i, W;
	int wt[20], val[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &wt[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &val[i]);
	scanf("%d", &W);
	printf("%f", fractionalKnapsack(wt, val, n, W));
	return 0;
}

