#include<stdio.h>
#include<string.h>

int isInterleaved(char *A, char *B, char *C)
{
    while(*C)
    {
        if(*A == *C)
            A++;
		else if(*B == *C)
			B++;
        else
            return 0;
        C++;
    }
    if(*A || *B)
        return 0;
    else
    	return 1;
}

int main()
{
    char A[] = "AC";
	char B[] = "BD";  
    char C[] = "ABCD";  
	printf("%d",isInterleaved(A, B, C));
    return 0;
}
