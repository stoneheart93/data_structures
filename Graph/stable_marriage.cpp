#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

#define N  4
 
int wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1)
{
    for(int i = 0; i < N; i++)
    {
		if(prefer[w][i] == m1)
    		return true;
		if(prefer[w][i] == m)
        	return false;
    }
}
 
void stableMarriage(int prefer[2*N][N])
{
    int wPartner[N], mFree[N];
 	
	memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, 0, sizeof(mFree));
    
	int freeCount = N;
 
    while(freeCount > 0)
    {
        int m;
        for(m = 0; m < N; m++)
        	if(mFree[m] == 0)
            	break;
 
        for(int i = 0; i < N && mFree[m] == 0; i++)
        {
            int w = prefer[m][i];
 
            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = 1;
                freeCount--;
            }
			else 
			{
                int m1 = wPartner[w-N];
				if(!wPrefersM1OverM(prefer, w, m, m1))
                {
                    wPartner[w - N] = m;
                    mFree[m] = 1;
                    mFree[m1] = 0;
                }
            } 
        }
    }
	printf("Woman\tMan\n");
    for(int i = 0; i < N; i++)
       printf("%d\t%d\n", i+N, wPartner[i]);
}

int main()
{
    int prefer[2*N][N] = { {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    stableMarriage(prefer);
    return 0;
}
