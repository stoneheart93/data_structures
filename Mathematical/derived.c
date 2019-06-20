/*
	add A, P number of times
	subtract A, Q number of times
	add B, R number of times
	subtract B, S number of times
	
	P*A - Q*A + R*B - S*B = X
	(P - Q)*A + (R - S)*B = X
	U*A + V*B = X
	
	If a[i] is derived from D, then |a[i] - D| = X
	
	U*A + V*B = |a[i] - D|
	
	-> Linear Diophantine Equation
*/

#include<stdio.h>
 
int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int countDerived(int a[], int n, int D, int A, int B)
{
	int gcdAB = gcd(A, B);
	
	int count = 0;
	int i;
	for(i = 0; i < n; i++)
	{
		if(abs(a[i] - D) % gcdAB == 0)
			count++;
	}
	return count;
}
 
int main()
{
    int D, A, B;
    int n, i;
    int a[20];
    scanf("%d%d%d", &D, &A, &B);
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    	scanf("%d", &a[i]);
    printf("%d", countDerived(a, n, D, A, B));
    return 0;
}
