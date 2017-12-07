#include<stdio.h>
#include<string.h>
#define NO_OF_CHARS 256

void print(char *list[], char* word, int list_size)
{
    static int map[NO_OF_CHARS];
    int i, j, count, word_size;
 
    for (i = 0; word[i]; i++)
        map[word[i]] = 1;
 	word_size = strlen(word);
 
    for (i = 0; i < list_size; i++)
    {
        for (j = 0, count = 0; list[i][j]; j++)
        {
            if (map[list[i][j]])
            {
                count++;
 				map[list[i][j]] = 0;
            }
        }
        
        if (count == word_size)
            printf("%s\n", list[i]);
 
        for (j = 0; word[j]; j++)
            map[word[j]] = 1;
    }
}
 
int main()
{
    char str[] = "sun";
    char *list[] = {"geeksforgeeks", "unsorted", "sunday", "just", "sss" };
    print(list, str, 5);
    return 0;
}
