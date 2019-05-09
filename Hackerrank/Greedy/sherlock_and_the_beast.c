#include<stdio.h>
#include<limits.h>

void printLargest(int n)
{
    int counter = 0;
    int maxthree = INT_MIN, maxfive = INT_MIN;

    while(1)
    {
        int three = 3 * counter;
        int five = n - three;

        if(three > n)
            break;
        
        if(five % 5 == 0)
        {
            if(three > maxthree)
            {
                maxthree = three;
                maxfive = five;
            }
        }
        counter++;
    }
    
    if(maxfive == INT_MIN && maxthree == INT_MIN)
    {
        printf("-1");
        return;
    }
    
    int i;
    for(i = 0; i < maxthree; i++)
        printf("5");
    
    for(i = 0; i < maxfive; i++)
        printf("3");
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printLargest(n);
        printf("\n");
    }
    return 0;
}
