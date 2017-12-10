#include<iostream>
#include<vector>
using namespace std;

void split(int num, vector<int> &out)
{
    vector<int> arr;
    while(num)
    {
        arr.push_back(num % 10);
        num = num / 10;
    }
    out.insert(out.end(), arr.rbegin(), arr.rend());
}
 
void addArrays(int a1[], int a2[], int m, int n)
{
    vector<int> out;
    int i = 0;
    while (i < m && i < n)
    {
        int sum = a1[i] + a2[i];
        if (sum < 10)
        	out.push_back(sum); 
        else
        	split(sum, out);
    	i++;
    }
 
    while (i < m)
        split(a1[i++], out);
 
    while (i < n)
        split(a2[i++], out);
 
    for(int x : out)
    	printf("%d ", x);
}

int main()
{
	int m, n;
	int a1[20], a2[20];
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
		scanf("%d", &a1[i]);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a2[i]); 
    addArrays(a1, a2, m, n); 
    return 0;
}
