//hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/memorise-me/

#include<iostream>
#include<unordered_map>
#include<stdio.h>
using namespace std;

void countOcc(int a[], int N, int query[], int Q)
{
    unordered_map<int, int> hash;
    
    for(int i = 0; i < N; i++)
        hash[a[i]]++;
    
    for(int i = 0; i < Q; i++)
    {
        if(hash.find(query[i]) != hash.end())
            printf("%d\n", hash[query[i]]);
        else
            printf("NOT PRESENT\n");
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int* a = new int[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    
    int Q;
    scanf("%d", &Q);
    int* query = new int[Q];
    for(int i = 0; i < Q; i++)
        scanf("%d", &query[i]);
    
    countOcc(a, N, query, Q);
    
    delete[] a;
    delete[] query;
   
    return 0;
}
