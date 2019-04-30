#include<stdio.h>
#include<stdlib.h>

void catch(int x, int y, int z)
{
    int cata = abs(x - z);
    int catb = abs(y - z);
    if(cata < catb)
        printf("Cat A\n");
    else if(catb < cata)
        printf("Cat B\n");
    else
        printf("Mouse C\n");
}

int main()
{
    int tc;
    int x, y, z;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d%d%d", &x, &y, &z);
        catch(x, y, z);
    }
    return 0;
}
