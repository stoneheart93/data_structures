#include<stdio.h>
#define NA -1
 
void moveToFront(int mPlusN[], int size)
{
	int i, j = 0;
  	for(i = 0; i < size; i++)
    {
    	if(mPlusN[i] != NA)
      		mPlusN[j++] = mPlusN[i];
    }
    while(j < size)
    	mPlusN[j++] = NA;
}
 
void merge(int mPlusN[], int N[], int m, int n)
{
	int i = m - 1, j = n - 1, k = m + n - 1; 
	while(j >= 0)
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
	int i, m = 5, n = 4;
	int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
	int N[] = {5, 7, 9, 25};
  
	moveToFront(mPlusN, m + n);
	merge(mPlusN, N, m, n);
 
	for(i = 0; i < m + n; i++)
		printf("%d ", mPlusN[i]);   
	return 0;

}

