#include<stdio.h>

int max(int a, int b)
{
	return (a > b)? a: b;
}
  
int min(int a, int b)
{
	return (a < b)? a: b;
}

int median(int a[], int n) 
{
	if(n % 2 == 0) 
    	return (a[n/2] + a[n/2 - 1]) / 2; 
    else
        return a[n/2]; 
}

int getMedian(int a1[], int a2[], int n) 
{ 
    if(n <= 0) 
    	return -1; 
    if(n == 1) 
    	return (a1[0] + a2[0]) / 2; 
    if (n == 2) 
        return (max(a1[0], a2[0]) + min(a1[1], a2[1])) / 2; 
  
    int m1 = median(a1, n);  
    int m2 = median(a2, n);  
  
    if(m1 == m2) 
        return m1; 
  
    if(m1 < m2) 
    { 
        if (n % 2 == 0) 
            return getMedian(a1 + n/2 - 1, a2, n - n/2 + 1); 
        else
			return getMedian(a1 + n/2, a2, n - n/2); 
    } 
	else
	{
	    if (n % 2 == 0) 
    	    return getMedian(a2 + n/2 - 1, a1, n - n/2 + 1); 
   		else
			return getMedian(a2 + n/2, a1, n - n/2);
	}
} 

int main()
{
	int a1[100], a2[100];
    int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a1[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &a2[i]);
	
	printf("%d", getMedian(a1, a2, n));
    return 0;
}     
