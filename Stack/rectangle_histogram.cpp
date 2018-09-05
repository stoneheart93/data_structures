#include<stdio.h>
#include<stack>
using namespace std;

/*
https://stackoverflow.com/questions/4311694/maximize-the-rectangular-area-under-histogram
To find the maximal rectangle, if for every bar x, we know the first smaller bar on its each side, 
let's say l and r, we are certain that height[x] * (r - l - 1) is the best shot we can get by using height of bar x.
It is possible, by using a increasing stack.
*/

int getMaxArea(int hist[], int n)
{
    stack<int> s;
    int max_area = 0; 
    int tp;
    int area;
	int i = 0;
    while(i < n)
    {
        if(s.empty() || hist[i] >= hist[s.top()])
        {
            s.push(i);
			i++;
		}
        else
        {
            tp = s.top();
            s.pop();
            area = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            if(area > max_area)
                max_area = area;
        }
    }

    while(!s.empty())
    {
        tp = s.top();
        s.pop();
        area = hist[tp] * (s.empty() ? i : i - s.top() - 1);

        if(area > max_area)
        	max_area = area;
    }
    return max_area;
}

int main()
{
	int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = 7;
    printf("Maximum area is %d", getMaxArea(hist, n));
    return 0;
}
