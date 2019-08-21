// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/binary-swap-b91d9bef/description/

#include<stdio.h>

int minOperations(char* str1, char* str2)
{
    int count = 0;
    for(int i = 0; str1[i] && str2[i]; i++)
    {
        if(str1[i] != str2[i])
            count++;
    }
    return (count % 2 == 0 ? count / 2 : -1);
}

int main()
{
    char str1[100005], str2[100005];
    scanf("%s %s", &str1, &str2);
    printf("%d", minOperations(str1, str2));
    return 0;
}
