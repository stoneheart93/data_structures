#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> &p1, pair<int, int> &p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

void sortFrequency(int a[], int n)
{
	unordered_map<int, int> hash;
	for(int i = 0; i < n; i++)
		hash[a[i]]++;
		
	int s = hash.size();
	pair<int, int> p[s];
	
	int i = 0;
	for(auto it = hash.begin(); it != hash.end(); it++)
		p[i++] = make_pair(it->first, it->second);
	
	sort(p, p + s, compare);
 
    for(int i = 0; i < s; i++)
    {
		int freq = p[i].second;
        while(freq--)
            printf("%d ", p[i].first);
    }
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sortFrequency(a, n);
	return 0;
}

