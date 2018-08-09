#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
 
void pythagoreanTriplet(int a[], int n)
{	
    int l, r;
	int found = 0;
    
    for(int i = 0; i < n; i++)
		a[i] *= a[i];
	
	sort(a, a + n);
    
    for(int i = n - 1; i >= 2; i--)
    {
    	l = 0; 
        r = i - 1; 
		while(l < r)
        {
            if(a[i] == a[l] + a[r])
            {
            	found = 1;
                l++;
                r--;
			}
            else if(a[i] > a[l] + a[r])
                l++;
            else 
                r--;
        }
    }
    if(found == 1)
    	printf("Pythagorean Triplet");
    else
    	printf("No Triplet");
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	pythagoreanTriplet(a, n);
	return 0;
}

/*
ip
5
3 1 4 6 5
op
Triplet is 3, 4, 5
*/
