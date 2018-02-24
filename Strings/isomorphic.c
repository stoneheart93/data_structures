#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NO_OF_CHARS 256

int areIsomorphic(char* str1, char* str2)
{
	int m = strlen(str1);
	int n = strlen(str2);
 
    if (m != n)
      return 0;
 
    static int marked[NO_OF_CHARS];
	int map[NO_OF_CHARS];
    memset(map, -1, sizeof(map));
 
	int i;
    for(i = 0; i < n; i++)
    {
        if(map[str1[i]] == -1)
        {
            if(marked[str2[i]])
                return 0;
 			marked[str2[i]] = 1;
 			map[str1[i]] = str2[i];
        }
		else if(map[str1[i]] != str2[i])
            return 0;
	}
 	return 1;
}
 
int main()
{
	char str1[] = "aab";
	char str2[] = "xxy";
	if(areIsomorphic(str1, str2))
		printf("Isomorphic");
	else
		printf("Not isomorphic");
	return 0;
}

