#include<stdio.h>
#define NO_OF_CHARS 256
 
static int count[NO_OF_CHARS];
 
int fact(int n)
{
    return (n <= 1)? 1: n * fact(n-1);
}
 
/*
value of count[i] -> Alphabetical position of i in the string
string: g-1, i-2, n-3, r-4, s-5, t-6
*/
void populateAndIncreaseCount(char* str)
{
    int i;
    for(i = 0; str[i]; i++)
    	count[str[i]]++;
 
    for(i = 1; i < NO_OF_CHARS; i++)
        count[i] += count[i-1];
}

void updatecount(char ch)
{
    int i;
    for(i = ch; i < NO_OF_CHARS; i++)
		count[i]--;
}
 
int findRank(char* str)
{
    int len = strlen(str);
    int mul = fact(len);
    int rank = 1, i;
 
    populateAndIncreaseCount(str);
 
    for(i = 0; i < len; i++)
    {
		mul /= len - i;
		rank += count[str[i] - 1] * mul;
        updatecount(str[i]); //After fixing str[i], consider the string str[i+1] to str[len-1] and update count array accordingly.
	}
    return rank;
}
 
int main()
{
    char str[] = "string";
    printf ("%d", findRank(str));
    return 0;
}
