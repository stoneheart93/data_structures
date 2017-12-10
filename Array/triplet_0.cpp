#include<iostream>
#include<algorithm>
using namespace std;

void tripletsZero(int a[], int n)
{
    int l, r;
	int found = 0;
    
	sort(a, a + n);
	
	for(int i = 0; i < n - 2; i++)
    {
    	l = i + 1; 
        r = n - 1; 
		while(l < r)
        {
            if(a[i] + a[l] + a[r] == 0)
            {
                printf("Triplet is %d, %d, %d\n", a[i], a[l], a[r]);
                l++;
                r--;
                found = 1;
            }
            else if(a[i] + a[l] + a[r] < 0)
                l++;
            else 
                r--;
        }
    }
    if(found == 0)
    	printf("No triplets");
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	tripletsZero(a, n);
	return 0;
}

/*
ip
5
0 -1 2 -3 1 
op
-3 1 2
-1 0 1
*/
