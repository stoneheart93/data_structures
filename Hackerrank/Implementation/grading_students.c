#include<stdio.h>

int gradingStudents(int n)
{
	if(n >= 38)
	{
		if((n + 1) % 5 == 0 )
			return n + 1;
		else if((n + 2) % 5 == 0)
			return  n + 2;
		else
			return n;
	}
	else
		return n;
}

int main()
{
	int tc, n;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &n);
		printf("%d\n", gradingStudents(n));
	}
	return 0;
}
