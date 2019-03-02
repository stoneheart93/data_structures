#include<stdio.h>

void printUncommon(int a1[], int a2[], int m, int n)
{
	int i = 0, j = 0;
    while (i < m && j < n) 
	{
		if(a1[i] < a2[j]) 
	 		printf("%d ", a1[i++]);
        else if(a2[j] < a1[i]) 
			printf("%d ", a2[j++]);
        else 
		{
            i++;
            j++;
        }
    }
    while(i < m) 
		printf("%d ", a1[i++]);
    while(j < n) 
		printf("%d ", a2[j++]);
}
  
int main()
{
	int i, m, n;
	int a1[100], a2[100];
	
	scanf("%d %d", &m, &n);
	for(i = 0; i < m; i++)
		scanf("%d", &a1[i]);
	
	for(i = 0; i < n; i++)
		scanf("%d", &a2[i]);
	
	printUncommon(a1, a2, m, n);
	return 0;

}
