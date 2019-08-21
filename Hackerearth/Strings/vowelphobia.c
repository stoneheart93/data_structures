// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/vowels/

#include<stdio.h>

int countVowels(char* str)
{
    int count = 0;
    
    for(int i = 0; str[i]; i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            count++;
    }
    return count;
}

int main()
{
    int tc;
    char str[255];
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%s", &str);
        printf("%d\n", countVowels(str));
    }
    return 0;
}
