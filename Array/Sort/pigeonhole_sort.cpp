#include <iostream>
#include <vector>
using namespace std;
 
void pigeonhole_sort(int a[], int n)
{
    int min = a[0], max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] < min)
            min = a[i];
        if(a[i] > max)
            max = a[i];
    }
    int range = max - min + 1; 
    
    vector<int> holes[range];
 
    for(int i = 0; i < n; i++)
        holes[a[i] - min].push_back(a[i]);
 
    int index = 0;  
    for(int i = 0; i < range; i++)
    {
		for(int j = 0; j < holes[i].size(); j++)
    		a[index++] = holes[i][j];
    }
}

int main() 
{
    int n;
	int a[20];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	pigeonhole_sort(a, n);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
