#include <stdio.h>

int getOddOccurrence(int a[], int n)
{
    int i;
    int res = 0; 
    for(i = 0;i < n; i++)     
    	res = res ^ a[i];
    return res;
}
 
int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", getOddOccurrence(a, n));
    return 0;
}
