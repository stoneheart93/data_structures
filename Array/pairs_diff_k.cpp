#include<iostream>
#include<algorithm>
using namespace std;

int pairsDiffK(int a[], int n, int k)
{
    int count = 0;
    sort(a, a + n);
	int l = 0, r = 0;
    
	while(r < n)
    {
        if(a[r] - a[l] == k)
        {
            count++;
            l++;
            r++;
        }
        else if(a[r] - a[l] > k)
            l++;
        else 
		    r++;
    }   
    return count;
}

int main() 
{
    int n, k;
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	printf("%d ", pairsDiffK(a, n, k));
	return 0;
}

