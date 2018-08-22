#include<stdio.h>
#include<string.h>
#include<limits.h>

void minDistinctWindow(char* S) 
{
	
	static int visited[256];
	static int hasFound[256];
	
	int sLen = strlen(S);
	int distinctLen = 0;
	
	int minWindowLen = INT_MAX;
	int count = 0;
	int i, begin, end;
	int minWindowBegin, minWindowEnd;
	
	for(i = 0; i < sLen; i++)
	{
		if(!visited[S[i]])
		{
			visited[S[i]] = 1;
			distinctLen++;
		}
	}
  	
	for(begin = 0, end = 0; end < sLen; end++) 
	{
    	// skip characters not in T
    	if(!visited[S[end]]) 
			continue;
    	hasFound[S[end]]++;
    	if(hasFound[S[end]] == 1)
      		count++;
 
    	// if window constraint is satisfied
    	if(count == distinctLen) 
		{
      		// advance begin index as far right as possible,
      		// stop when advancing breaks window constraint.
      		while(!visited[S[begin]] || hasFound[S[begin]] > 1) 
			{
        		if (hasFound[S[begin]] > 1)
          			hasFound[S[begin]]--;
        		begin++;
			}
			
			int windowLen = end - begin + 1;
			if(windowLen < minWindowLen) 
			{
        		minWindowBegin = begin;
        		minWindowEnd = end;
        		minWindowLen = windowLen;
			}	
    	}
	}
	
	for(i = minWindowBegin; i <= minWindowEnd; i++)
    	printf("%c", S[i]);
    printf("\nMinimum window length: %d", minWindowLen);
}

int main()
{
    char S[20];
    gets(S);
    minDistinctWindow(S);
    return 0;
}
