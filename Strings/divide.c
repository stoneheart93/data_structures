#include<stdio.h>
#include<string.h>

void divide(char* str, int n)
{
    int str_size, part_size, i;
    str_size = strlen(str);
    if(str_size % n != 0)
    {
        printf("\n Invalid Input: String size is not divisible by n");
        return;
    }
    part_size = str_size / n;
    for(i = 0; i < str_size; i++)
    {
        if(i % part_size == 0)
            printf("\n"); 
        printf("%c", str[i]);
    }
}

int main()
{
    char str[20];
    int n;
    scanf("%s", str);
    scanf("%d", &n);
    divide(str, n);
    return 0;
}
