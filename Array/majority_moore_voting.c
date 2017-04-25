#include<stdio.h>
 
int find(int a[], int n)
{
    int maj = 0, count = 1, i;
    for(i = 1; i < n; i++)
    {
        if(a[i] == a[maj])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj = i;
            count++;
        }
    }
    return a[maj];
}

int isMajority(int a[], int n, int cand)
{
    int i, count = 0;
    for(i = 0; i < n; i++)
    {
		if(a[i] == cand)
        	count++;
	}
    if(count > n/2)
    	return 1;
    else
    	return 0;
}
 
int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	int cand = find(a, n);
	if(isMajority(a, n, cand))
    	printf("%d", cand);
  	else
    	printf("No Majority Element");
	return 0;
}

/*
ip
5
1 3 3 1 2
op
No Majority Element
*/

