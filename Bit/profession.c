#include<stdio.h>

int countSetBits(int n)
{
    int count = 0;
    while(n != 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

char findProfession(int level, int pos)
{
	int c = countSetBits(pos - 1);
	return (c % 2)? 'd' : 'e';
}

int main()
{
    int level, pos;
    scanf("%d%d", &level, &pos);
    (findProfession(level,pos) == 'e')? printf("Engineer") : printf("Doctor");
    return 0;
}
