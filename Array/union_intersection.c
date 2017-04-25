#include<stdio.h>

int printUnion(int a1[], int a2[], int m, int n)
{
	int i = 0, j = 0;
  	while (i < m && j < n)
  	{
    	if (a1[i] < a2[j])
      		printf("%d ", a1[i++]);
    	else if (a2[j] < a1[i])
      		printf("%d ", a2[j++]);
    	else
    	{
      		printf("%d ", a1[i++]);
      		j++;
    	}
  	}
 	while(i < m)
   		printf("%d ", a1[i++]);
  	while(j < n)
   		printf("%d ", a2[j++]);
}

int printIntersection(int a1[], int a2[], int m, int n)
{
	int i = 0, j = 0;
  	while (i < m && j < n)
  	{
    	if (a1[i] < a2[j])
      		i++;
    	else if (a2[j] < a1[i])
      		j++;
    	else
    	{
      		printf("%d ", a1[i++]);
      		j++;
    	}
  	}
}

int main() 
{
    int n, m, i;
	int a1[20], a2[20];
	scanf("%d", &m);
	for(i = 0; i < m; i++)
		scanf("%d", &a1[i]);
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a2[i]);
	
	printf("\nUnion:\n");
	printUnion(a1, a2, m, n);
	printf("\nIntersection:\n");
	printIntersection(a1, a2, m, n);
	
	return 0;
}

/*
ip
5
1 2 4 5 6
4
2 3 5 7
op
Union:
1 2 3 4 5 6 7
Intersection:
2 5
*/
