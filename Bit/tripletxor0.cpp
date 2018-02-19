#include<iostream>
#include<unordered_set>
using namespace std;

int tripletXor0(int a[], int n) 
{
	unordered_set<int> s;
    for(int i = 0; i < n; i++)
    	s.insert(a[i]);
    
	int count = 0;
    
	for(int i = 0; i < n; i++) 
	{
        for(int j = i + 1; j < n; j++) 
		{
        	int xr = a[i] ^ a[j];
			if(s.find(xr) != s.end() && xr != a[i] && xr != a[j])
            	count++;
        }
    }
     
    return count / 3;
}

int main()
{
	int n, sum;
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", tripletXor0(a, n));
	return 0;
}

/*
ip
6
1 3 5 10 14 15
op
2
*/
