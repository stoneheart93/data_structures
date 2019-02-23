#include<iostream>
#include<vector>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while(n != 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
 
void sortBySetBitCount(int a[], int n) 
{ 
    vector<vector<int> > count(32); 
    int setbitcount = 0;
	    
    for(int i = 0; i < n; i++) 
    { 
        setbitcount = countSetBits(a[i]); 
        count[setbitcount].push_back(a[i]); 
    } 
  
    int j = 0;
	for(int i = 31; i >= 0; i--) 
    { 
        vector<int> v1 = count[i]; 
        for(int i = 0; i < v1.size(); i++) 
            a[j++] = v1[i]; 
    } 
} 
  
int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sortBySetBitCount(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
 	return 0;
}

