#include<stdio.h>

int MSB(int n)
{
	int msb_p = -1;
	while(n)
	{
		n = n >> 1;
		msb_p++;
	}
	return msb_p;
}

int andOp(int x, int y)
{
	int result = 0;
	while(x && y)
	{
		int msb_p1 = MSB(x);
		int msb_p2 = MSB(y);
		
		if(msb_p1 != msb_p2)
			break;
			
		int msb_val = 1 << msb_p1;
		result += msb_val;
		x -= msb_val;
		y -= msb_val;
	}
	return result;
}

int main()
{
	int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", andOp(x, y));
    return 0;
}

/*
ip
10 15
op 
8
*/
