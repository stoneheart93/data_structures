#include<iostream>
#include<algorithm>
using namespace std;

int minPlatforms(int a[], int d[], int n)
{
	sort(a, a + n);
	sort(d, d + n);
	
	int i = 0, j = 0;
	int platforms = 0, result = 0;
	while(i < n && j < n)
	{
		if(a[i] <= d[j])
		{
			i++;
			platforms++;
			if(platforms > result)
				result = platforms;	
		}
		else
		{
			j++;
			platforms--;
		}
	}
	return result;
}

int main()
{
	int n;
	int a[50], d[50];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i], &d[i]);
	}
	printf("%d", minPlatforms(a, d, n));
	return 0;
}


/*
ip
6
900 910
940 1200
950 1120
1100 1130
1500 1900
1800 2000
op
3
*/ 
