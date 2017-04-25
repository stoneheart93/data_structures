#include<stdio.h>

int rand50()
{
    return rand() & 1;
}
 
int rand75()
{
    return rand50() | rand50();
}
 
int main()
{
	int i;
    srand(time(NULL));
    for(i = 0; i < 50; i++)
        printf("%d", rand75()); 
    return 0;
}

