#include<stdio.h>

struct Point
{
    int x, y;
};

Point mirror(Point p1, Point p2)
{
    Point p;
    int x_diff = p2.x - p1.x;
    int y_diff = p2.y - p1.y;
    p.x = p2.x + x_diff;
    p.y = p2.y + y_diff;
    return p;
}

int main()
{
    int t;
    Point p1, p2;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y);
        Point p = mirror(p1, p2);
        printf("%d %d\n", p.x, p.y);
    }
    return 0;
}
