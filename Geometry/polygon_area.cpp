#include<iostream>
#include<stdio.h>
using namespace std;

struct Point
{
    int x, y;
};

double polygonArea(Point points[], int n)
{
    double area = 0.0;
	
	for(int i = 0; i < n - 1; i++)
    {
        Point p = points[i];
        Point q = points[i + 1];
        area += (p.x * q.y) - (q.x * p.y);
    }
 	return (area / 2.0);
}

int main()
{
    
	Point points[4] = {{0, 1}, {2, 3}, {4, 7}};
    int n = 4;
    points[3] = points[0];
    printf("%f", polygonArea(points, n));
    return 0;
}
