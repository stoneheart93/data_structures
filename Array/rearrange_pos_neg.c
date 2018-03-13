#include<stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void rearrangePosNeg(int a[], int n)
{
    int i = -1, j;
    for(j = 0; j < n; j++)
    {
        if(a[j] < 0) // >=
        {
            i++;
        	swap(&a[i], &a[j]);
        }
    }
    
	int pos = i + 1, neg = 0;
	while(pos < n && neg < pos && a[neg] < 0)
    //int pos = 0, neg = i + 1;
	//while(neg < n && pos < neg && a[pos] >= 0)
    {
        swap(&a[neg], &a[pos]);
        pos++; 
        neg += 2;
    	//pos +=2;
        //neg++;
    }
}
 
int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	rearrangePosNeg(a, n);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
} 

/*
ip
9
-1 2 -3 4 5 6 -7 8 9
op
4 -3 5 -1 6 -7 2 8 9
*/
