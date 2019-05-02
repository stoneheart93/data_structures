#include<stdio.h>

long long int a_occurence(char* str, long long int n)
{
    int len = strlen(str);
    int i, occ = 0;
    long long int count = 0;
    
    for(i = 0; str[i]; i++)
    {
        if(str[i] == 'a')
            occ++;
    }
    
    count = (n / len) * occ;
    
    int remaining = n % len;
    for(i = 0; i < remaining; i++)
    {
        if(str[i] == 'a')
            count++;
    }
    return count;
}


int main()
{
    char str[200];
    long long int n;
    
    scanf("%s", str);
    scanf("%lld", &n);
    
    printf("%lld", a_occurence(str, n));
    return 0;
}
