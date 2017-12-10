#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
void bucket_sort(float a[], int n)
{
    vector<float> b[n];
    
    for(int i = 0; i < n; i++)
       b[n * a[i]].push_back(a[i]);
 
    for(int i = 0; i < n; i++)
       sort(b[i].begin(), b[i].end());
 
    int index = 0;
    for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < b[i].size(); j++)
    		a[index++] = b[i][j];
	}
}

int main() 
{
    int n;
	float a[20];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	bucket_sort(a, n);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
