#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

void missingNumbers(int a[], int n, int b[], int m)
{
    unordered_map<int, int> hash;
    for(int i = 0; i < m; i++)
        hash[b[i]]++;

    for(int i = 0; i < n; i++)
    {
        if(hash.find(a[i]) != hash.end())
        {
            int freq = hash.find(a[i])->second;
            if(freq == 1)
                hash.erase(a[i]);
            else
            {
                freq--;
                hash[a[i]] = freq;
            }
        }
    }

    vector<int> missing;
    for(auto it : hash)
        missing.push_back(it.first);

    sort(missing.begin(), missing.end());

    for(int i = 0; i < missing.size(); i++)
        printf("%d ", missing[i]);
}

int main()
{
    int n, m;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    int* b = (int*)malloc(m * sizeof(int)); 
    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    missingNumbers(a, n, b, m);
    return 0;
}

