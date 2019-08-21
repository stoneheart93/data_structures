// https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/dna-pride/

#include<stdio.h>
#include<string.h>

void correctPair(char* str, int n)
{
    for(int i = 0; i < n; i++)
    {
        switch(str[i])
        {
            case 'A': str[i] = 'T';
                      break;
            case 'T': str[i] = 'A';
                      break;
            case 'C': str[i] = 'G';
                      break;
            case 'G': str[i] = 'C';
                      break;
            default: goto exit;
        }
    }
    printf("%s\n", str);
    return 0;
    exit:
        printf("Error RNA nucleobases found!\n");
}

int main()
{
    int tc, n;
    char str[1000005];
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        scanf("%s", &str);
        correctPair(str, n);
    }
    return 0;
}
