#include<iostream>
#include<algorithm>
using namespace std;

void findLarger(int a[], int n)
{
    sort(a, a + n);
 
 	int i;
    for(i = n/2; i < n; i++)
    	printf("%d ", a[i]);    
}

int main() 
{
    int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	findLarger(a, n);
	return 0;
}
 
 
