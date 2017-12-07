#include<stdio.h>
#define NA -1
 
void moveToEnd(int mPlusN[], int size)
{
	int i = 0, j = size - 1;
  	for(i = size - 1; i >= 0; i--)
    {
    	if(mPlusN[i] != NA)
    	{
      		mPlusN[j] = mPlusN[i];
      		j--;
    	}
    }
}
 
int merge(int mPlusN[], int N[], int m, int n)
{
	int i = n, j = 0, k = 0; 
	while (k < (m + n))
  	{	
    	if ((i < (m + n) && mPlusN[i] <= N[j]) || (j == n))
    	{
      		mPlusN[k] = mPlusN[i];
      		k++;
      		i++;
    	}
    	else  
    	{
      		mPlusN[k] = N[j];
      		k++;
      		j++;
    	}
 	}
}
  
int main()
{
	int i, m = 5, n = 4;
	int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
	int N[] = {5, 7, 9, 25};
  
	moveToEnd(mPlusN, m + n);
	merge(mPlusN, N, m, n);
 
	for(i = 0; i < m + n; i++)
		printf("%d ", mPlusN[i]);   
	return 0;

}

