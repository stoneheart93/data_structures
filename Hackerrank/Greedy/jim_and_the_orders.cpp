#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void delivery(int order[], int prep[], int n)
{
    pair<int, int> s[n];
    int index = 0;

    for(int i = 0; i < n; i++)
        s[index++] = make_pair(i+1, order[i] + prep[i]);

    sort(s, s + n, compare);

    for(int i = 0; i < n; i++)
        printf("%d ", s[i].first);
}

int main()
{
    int n;
    scanf("%d", &n);
    int* order = (int*)malloc(n * sizeof(int));
    int* prep = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d%d", &order[i], &prep[i]);
    delivery(order, prep, n);
    return 0;
}
