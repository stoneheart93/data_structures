#include<iostream>
#include<algorithm>
using namespace std;
 
void tripletSum(int a[], int n, int sum)
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
            if(a[i] + a[l] + a[r] == sum)
            {
            	printf("Triplet is %d, %d, %d\n", a[i], a[l], a[r]);
                found = 1;
                l++;
                r--;
			}
            else if(a[i] + a[l] + a[r] < sum)
                l++;
            else 
                r--;
        }
    }
    if(found == 0)
    	printf("No triplet");
}

int main()
{
	int n, i, sum;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &sum);
	tripletSum(a, n, sum);
	return 0;
}

/*
ip
6
12 3 6 1 6 9
24
op
Triplet is 3, 9, 12
Triplet is 6, 6, 12
*/
