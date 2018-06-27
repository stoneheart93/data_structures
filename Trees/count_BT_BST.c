#include<stdio.h>

int factorial(int n)
{
    int res = 1;
	int i;
    for(i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

void count_BT_BST(int n)
{
	int a = factorial(2 * n);
	int b = factorial(n + 1);
	int c = factorial(n);

	int bst = a/(b * c);
	int bt = a/b;
	
	printf("\nNo of possible BSTs %d", bst);
	printf("\nNo of possible BTs %d", bt);
}

int main()
{
	int n;
	scanf("%d", &n);
	count_BT_BST(n);
	return 0;
}
