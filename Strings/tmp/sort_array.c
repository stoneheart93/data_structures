#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int compare(const void* a, const void* b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}
 
int main ()
{
    char *a[] = {"Banana", "Apple", "Mango"};
    int n = 3;
    int i;
 
    qsort(a, n, sizeof(char*), compare);
    
    for (i = 0; i < n; i++)
        printf("%s \n", a[i]);
 
    return 0;
}
