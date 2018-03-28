#include<stdio.h>
#include<math.h>

int sum_nodes(int level)
{
	int leaf_nodes = pow(2, level - 1);
	int sum = ((leaf_nodes * (leaf_nodes + 1)) / 2);
	return sum * level;
}

int main()
{
	int level;
	scanf("%d", &level);
	printf("%d",sum_nodes(level));
	return 0;
}

