#include<stdio.h>
#include<stdlib.h>

int minBeautiful(char* str, int n)
{
    int count = 0;
    int i = 0;
    while(i + 3 - 1 < n)
    {
        if(str[i] == '0' && str[i+1] == '1' && str[i+2] == '0')
        {
            str[i+2] = '1';
            count++;
            i += 3;
        }
        else
            i++;
        
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    char* str =(char*)malloc(n * sizeof(char));
    scanf("%s", str);
    printf("%d", minBeautiful(str, n));
    return 0;
}
