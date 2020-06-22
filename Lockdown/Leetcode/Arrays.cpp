485. Max Consecutive Ones

https://leetcode.com/problems/max-consecutive-ones/

int max(int a, int b)
{
    return a > b ? a : b;
}

int findMaxConsecutiveOnes(int* a, int n)
{
    int count = 0;
    int max_count = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == 1)
        {
            count++;
            max_count = max(max_count, count);
        }
        else
            count = 0;
    }
    
    return max_count;
}

Time Complexity - O(n)