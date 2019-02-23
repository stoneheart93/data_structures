#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<float.h>
using namespace std;

struct Point
{
    int x, y;
};

bool compareX(Point a, Point b)
{
	return a.x < b.x;
}

bool compareY(Point a, Point b)
{
    return a.y < b.y;
}

float dist(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

float bruteForce(Point P[], int n)
{
    float min_dist = FLT_MAX;
    for(int i = 0; i < n; i++)
    {
    	for(int j = i + 1; j < n; j++)
        {
        	min_dist = min_dist < dist(P[i], P[j]) ? min_dist : dist(P[i], P[j]);
        }
    }
    return min_dist;
}

float stripClosest(Point Sy[], int size, float d)
{
        float min = d;
        for(int i = 0; i < size; i++)
        {
                for(int j = i + 1; j < size && ((Sy[j].y - Sy[i].y) < min) ; j++)
                {
                        min = min < dist(Sy[j], Sy[i]) ? min : dist(Sy[j], Sy[i]);
                }
        }
        return min;
}

float closestUtil(Point Px[], Point Py[], int n)
{
        if(n <= 3)
                return bruteForce(Px, n);

    int mid = n/2;
    Point midpoint = Px[mid];

    Point Pyl[mid + 1];
    Point Pyr[n - mid - 1];
    int l = 0, r = 0;
    for(int i = 0; i < n; i++)
    {
        if(Py[i].x <= midpoint.x)
            Pyl[l++] = Py[i];
    	else
        	Pyr[r++] = Py[i];
    }

    float dl = closestUtil(Px, Pyl, mid + 1);
    float dr = closestUtil(Px + mid + 1, Pyr, n - mid - 1);
    float d = min(dl, dr);

    Point Sy[n];
    int j = 0;
    for(int i = 0; i < n; i++)
   	{
        if(abs(Py[i].x - midpoint.x) < d)
            Sy[j++] = Py[i];
	}

    float stripmin = stripClosest(Sy, j, d);

    return stripmin < d ? stripmin : d;
}
float closest(Point P[], int n)
{
    Point Px[n], Py[n];

    for(int i = 0; i < n; i++)
    {
    	Px[i] = P[i];
        Py[i] = P[i];
    }

    sort(Px, Px + n, compareX);
	sort(Py, Py + n, compareY);

    return closestUtil(Px, Py, n);
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = 6;
    printf("%f", closest(P, n));
    return 0;
}
