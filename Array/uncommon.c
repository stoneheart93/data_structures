#include<stdio.h>

int printUncommon(int a1[], int a2[], int n1, int n2)
{
	int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) 
	{
		if(a1[i] < a2[j]) 
		{
        	printf("%d ", a1[i]);
            i++;
            k++;
        }
        else if(a2[j] < a1[i]) 
		{
        	printf("%d ", a2[j]);
            j++;
            k++;
        }
        else 
		{
            i++;
            j++;
        }
    }
    while(i < n1) 
	{
    	printf("%d ", a1[i]);
        i++;
        k++;
    }
    while(j < n2) 
	{
    	printf("%d ", a2[j]);
        j++;
        k++;
    }
}
  
int main()
{
	int i, n1, n2;
	int a1[100], a2[100];
	
	scanf("%d %d", &n1, &n2);
	for(i = 0; i < n1; i++)
		scanf("%d", &a1[i]);
	
	for(i = 0; i < n2; i++)
		scanf("%d", &a2[i]);
	
	printUncommon(a1, a2, n1, n2);
	return 0;

}
