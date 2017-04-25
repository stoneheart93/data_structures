#include<stdio.h>
#include<string.h>
#define INIT_MAX 999999

void minWindow(char* S, char* T) 
{
	static int needToFind[256];
	static int hasFound[256];
	
	int sLen = strlen(S);
	int tLen = strlen(T);
	
	int minWindowLen = INIT_MAX;
	int count = 0;
	int i, begin, end;
	int minWindowBegin, minWindowEnd;
	
	for(i = 0; i < tLen; i++)
		needToFind[T[i]]++;
 
  	
	for(begin = 0, end = 0; end < sLen; end++) 
	{
    	// skip characters not in T
    	if(needToFind[S[end]] == 0) 
			continue;
    	hasFound[S[end]]++;
    	if(hasFound[S[end]] <= needToFind[S[end]])
      		count++;
 
    	// if window constraint is satisfied
    	if(count == tLen) 
		{
      		// advance begin index as far right as possible,
      		// stop when advancing breaks window constraint.
      		while (needToFind[S[begin]] == 0 || hasFound[S[begin]] > needToFind[S[begin]]) 
			{
        		if (hasFound[S[begin]] > needToFind[S[begin]])
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
}

int main()
{
    char S[20];
    char T[20];
    gets(S);
    gets(T);
    minWindow(S, T);
    return 0;
}
