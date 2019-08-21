// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/difficult-characters/

#include<utility>
#include<algorithm>
using namespace std;

bool compare(pair<char, int> a, pair<char, int> b)
{
    if(a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

void difficulty(char* str)
{
    int count[26] = {0};
    for(int i = 0; str[i]; i++)
        count[str[i] - 'a']++;
        
    pair<char, int> count_pair[26];
    for(int i = 0; i < 26; i++)
        count_pair[i] = make_pair(i +'a', count[i]);
    
    sort(count_pair, count_pair + 26, compare);
    
    for(int i = 0; i < 26; i++)
        printf("%c ", count_pair[i].first);
}

int main()
{
    int tc;
    scanf("%d", &tc);
    char str[1000005];
    while(tc--)
    {
        scanf("%s", str);
        difficulty(str);
        printf("\n");
    }
    return 0;
}
