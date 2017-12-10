#include<stdio.h>
#define INIT_MAX 999999

int minDist(int a[], int n, int x, int y)
{
	int i, prev;
   	int min_dist = INIT_MAX;
   	for(i = 0; i < n; i++)
   	{
    	if(a[i] == x || a[i] == y)
     	{
      		prev = i;
       		break;
     	}
   	}
 
	for( ; i < n; i++)
   	{
    	if(a[i] == x || a[i] == y)
      	{
        	if(a[prev] != a[i] && (i - prev) < min_dist)
          	{
             	min_dist = i - prev;
             	prev = i;
          	}
          	else
            	prev = i;
      	}
   	}
 
   	return min_dist;
}

int main() 
{
    int n, i, x, y;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d %d", &x, &y);
	printf("Minimum distance: %d", minDist(a, n, x, y));
	return 0;
}

/*
ip
12
3 5 4 2 6 5 6 6 5 4 8 3
3 6
op
Minimum distance: 4
*/
