#include<stdio.h>
 
int minMaxProduct(int a1[], int a2[], int n1, int n2)
{
    int max = a1[0];
	int min = a2[0];
    int i;
    
    for(i = 1; i < n1; i++) 
	{
        if(a1[i] > max)
        	max = a1[i];
	}
	for(i = 1; i < n1; i++) 
	{
        if(a2[i] < min)
        	min = a2[i];
	}
 
    return max * min;
}
 
int main()
{
	int n1, n2, i;
	int a1[20], a2[20];
	scanf("%d", &n1);
	for(i = 0; i < n1; i++)
		scanf("%d", &a1[i]);
	scanf("%d", &n2);
	for(i = 0; i < n2; i++)
		scanf("%d", &a2[i]);
	printf("%d", minMaxProduct(a1, a2, n1, n2));
	return 0;
}

/*
ip
6
10 2 3 6 4 1
6
5 1 4 2 6 9
op
10
*/
