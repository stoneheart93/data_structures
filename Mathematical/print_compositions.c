#include<stdio.h>
int max_point;

void printArray(int a[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

 
void printCompositions(int n, int i)
{
	static int a[100];
	if (n == 0)
	{
    	printArray(a, i);
	}
	else if(n > 0)
	{
		int k; 
    	for (k = 1; k <= max_point; k++)
		{
			a[i]= k;
			printCompositions(n - k, i + 1);
		}
	}
}
  
int main()
{
	int score;
	scanf("%d", &score);
	scanf("%d", &max_point);
	printCompositions(score, 0);
	return 0;
}
