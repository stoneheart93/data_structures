#include<stdio.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int minJumps(int a[], int n)
{
	if(a[0] == 0)
		return -1;
		
	int ladder = a[0];
	int stairs = a[0];
	int jump = 1;
	
	int i;
	for(i = 1; i < n; i++)
	{
		if(i == n - 1)
			return jump;
			
		ladder = max(ladder, a[i]+i);
		
		stairs--;
		
		if(stairs == 0)
		{
			if(i >= ladder) //no more ladder eg: 3 0 0 0 3
				return -1;
				
			jump++;		
			stairs = ladder - i;
		}
	}
	return -1;
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    printf("%d", minJumps(a,n));
    return 0;
}
