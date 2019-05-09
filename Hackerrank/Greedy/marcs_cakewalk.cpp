#include<iostream>
#include<algorithm>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

bool compare(int a, int b)
{
    return a > b;
}

long int marcsCakewalk(int a[], int n) {
    sort(a, a + n, compare);
    long int result = 0;

    for(int i = 0; i < n; i++)
        result += (long int)a[i] * ((long int)1 << (long int)i);

    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cout << marcsCakewalk(a, n);
    return 0;
}

