#include<stdio.h>

int reverseBits(int num)
{
    int NO_OF_BITS = 32; 
    int reverse_num = 0, i, temp;
    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
    return reverse_num;
}
 
int main()
{
    int num;
	scanf("%d", &num); 
    printf("%d", reverseBits(num));
    return 0;
}

/*
ip 
2 
op
1073741824
*/
