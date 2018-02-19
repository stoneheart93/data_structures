#include<stdio.h>
 
int completionTime(int a[], int n, int p) 
{
	int time_req = 0;
	int i;
 
	for(i = 0; i < p; i++) 
	{
    	if(a[i] < a[p])
      		time_req += a[i];
    	else
      		time_req += a[p];
	}
 
	time_req += a[p];
 
	for(i = p + 1; i < n; i++) 
	{
    	if (a[i] < a[p])
    		time_req += a[i];
    	else
    		time_req += a[p] - 1;
	}
	return time_req;
}

int main() 
{
    int n, i, p;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &p);
	printf("%d", completionTime(a, n, p));
	return 0;
}

