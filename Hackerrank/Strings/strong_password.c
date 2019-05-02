#include<stdio.h>

int strongPassword(char* str, int n)
{
    // atleast length 6 
    int count = ((6 - n) < 0 ? 0 : 6 - n);

    int i, upper = 0, lower = 0, number = 0, special = 0;
    for(i = 0; str[i]; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            number++;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            upper++;
        else if(str[i] >= 'a' && str[i] <= 'z')
            lower++;
        else   
            special++;
    }

    int digit = 0;
    if(number == 0)
        digit++;
    if(upper == 0)
        digit++;
    if(lower == 0)
        digit++;
    if(special == 0)
        digit++;

    return count >= digit ? count : digit;
}

int main()
{
    int n;
    scanf("%d", &n);
    char* str = (char*)malloc(n * sizeof(char));
    scanf("%s", str);
    printf("%d", strongPassword(str, n));
    return 0;
}

