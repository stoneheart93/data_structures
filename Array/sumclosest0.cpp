#include<iostream>
#include<algorithm>
using namespace std;
#define INIT_MAX 9999999

void sumclosest0(int a[], int n)
{
	sort(a, a + n);
	int l = 0, r = n - 1;
	int sum, min_sum = INIT_MAX, min_l, min_r;
	while(l < r)
	{
		sum = a[l] + a[r];
		if(abs(sum) < abs(min_sum))
		{
      		min_sum = sum;
      		min_l = l;
      		min_r = r;
    	}
		if(sum > 0)
			r--;
		else if(sum < 0)
			l++;
	}
	printf("%d %d", a[min_l], a[min_r]);
}

int main()
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sumclosest0(a, n);
    return 0;    
}    

/*
ip
6
1 60 -10 70 -80 85
op
-80 85
*/
