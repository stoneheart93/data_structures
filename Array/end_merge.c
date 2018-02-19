#include<stdio.h>
#define NA -1
 
void merge(int mPlusN[], int N[], int m, int n) 
{
	int i = m - 1, j = n - 1, k = m + n - 1;
 
	while (j >= 0) 
	{
	    if(i >= 0 && mPlusN[i] > N[j]) 
		{
	    	mPlusN[k] = mPlusN[i];
			k--;
			i--; 
	    } 
		else 
		{
	      	mPlusN[k] = N[j];
      		k--;
			j--;
		}
	}
}
  
int main()
{
	int i, m = 5, n = 5;
	int mPlusN[] = {10, 12, 13, 14, 18, NA, NA, NA, NA, NA};
	int N[] = {16, 17, 19, 20, 22};
  
	merge(mPlusN, N, m, n);
 
	for(i = 0; i < m + n; i++)
		printf("%d ", mPlusN[i]);   
	return 0;

}
