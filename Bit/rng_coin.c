#include<stdio.h>

int rand50()
{
	return rand() & 1;
}

int randab(int a, int b)
{
	int outcomes = b - a + 1;
	int result;
	do
	{
		result = 0;
		// 2 ^ n -> b - a
		int i;
		for(i = 0; (1 << i) < outcomes; i++) 
			result = result << 1 | rand50();
		
	} while(result >= outcomes);
	return result + a;
}

int main()
{
	int a, b;
	
	srand(time(NULL));
	
	scanf("%d%d", &a, &b);
	int n = (b - a + 1) * 10; //cant prove
	
	int i;
	for(i = 0; i < n; i++)
		printf("%d\n", randab(a, b));
	return 0;
}
