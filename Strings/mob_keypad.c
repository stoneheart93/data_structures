#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char keypad[][5] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printCombinationRecur(int* input, char* output, int i, int index, int n)
{
	if(index == n)
		printf("%s\n", output);
	else
	{
		int digit = input[i];
		int len = strlen(keypad[digit]);
		int j;
		
		for(j = 0; j < len; j++)
		{
			output[index] = keypad[digit][j];
			printCombinationRecur(input, output, i + 1, index + 1, n);
		}
	}
}

void printCombination(int* input, int n)
{
	char* output = (char*)malloc(sizeof(char) * (n + 1));
	output[n] = '\0';
    printCombinationRecur(input, output, 0, 0, n);
	free(output);
}

int main()
{
	int input[] = {2,3,4};
	int n = 3;
    printCombination(input, n);
    return 0;
}
